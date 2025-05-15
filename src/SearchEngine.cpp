//
// Created by aliab on 4/29/2025.
//

#include "SearchEngine.h"

#include <algorithm>

Vertex::Vertex() {
  this->output = false;
  this->frequency = 0;
}

SearchEngine::SearchEngine() {
  this->trie.resize(1);
}

void SearchEngine::addWord(std::string& word) {
  int v = 0;
  for (auto c: word) {
    list.insert(c);
    if (trie[v].next.count(c) != 1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back();
    }

    v = trie[v].next[c];
    trie[v].frequency++;
  }

  trie[v].output = true;
}

bool SearchEngine::search(std::string& word) {
  int v = 0;
  for (auto c: word) {
    if (trie[v].next.count(c) != 1) {
      return false;
    }

    v = trie[v].next[c];
  }

  return trie[v].output;
}

void SearchEngine::dfs_construct(int v, std::string& cur, std::vector<std::string>& res, int limit) {
  if (res.size() >= limit) {
    return;
  }

  if (trie[v].output) {
    res.emplace_back(cur);
  }

  std::vector<std::pair<int, char>> best_next;
  for (auto c: list) {
    if (trie[v].next.count(c) == 1) {
      int u = trie[v].next[c];
      best_next.emplace_back(u, c);
    }
  }

  std::sort(best_next.begin(), best_next.end(), [&](const std::pair<int, char>& p1, const std::pair<int, char>& p2) {
    return trie[p1.first].frequency > trie[p2.first].frequency; // sort by characters that have a higher frequency of occurrence in the current level
  });

  for (auto [u, c]: best_next) {
    cur.push_back(c);
    dfs_construct(u, cur, res, limit);
    cur.pop_back();
  }
}

std::vector<std::string> SearchEngine::autoComplete(std::string& word, int limit) {
  std::vector<std::string> res;
  std::string cur;
  int v = 0;
  for (auto c: word) {
    if (trie[v].next.count(c) != 1) {
      return {};
    }
    v = trie[v].next[c];
  }

  cur = word;
  dfs_construct(v, cur, res, limit);
  return res;
}