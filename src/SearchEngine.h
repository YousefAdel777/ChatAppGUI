//
// Created by aliab on 4/29/2025.
//

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <set>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

class Vertex {
  public:
    std::unordered_map<char, int> next;
    bool output;
    int frequency;
    std::unordered_set<int> ids;

    Vertex();
};


class SearchEngine {
  public:
     std::vector<Vertex> trie;
     std::unordered_set<char> list;
     SearchEngine();
     void addWord(std::string&);
    void addWordWithId(std::string&, int);
     bool search(std::string&);
     std::vector<std::string> autoComplete(std::string&, int);
    std::unordered_set<int> getIds(std::string&);
    // void clear();

  private:
    void collectIds(int node, std::unordered_set<int>& result);
     void dfs_construct(int v, std::string&, std::vector<std::string>&, int limit);
};



#endif //SEARCHENGINE_H
