//
// Created by aliab on 4/29/2025.
//

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

class Vertex {
  public:
    std::unordered_map<char, int> next;
    bool output;
    int frequency;

    Vertex();
};


class SearchEngine {
  public:
     std::vector<Vertex> trie;
     std::unordered_set<char> list;
     SearchEngine();
     void addWord(std::string&);
     bool search(std::string&);
     std::vector<std::string> autoComplete(std::string&, int);

  private:
     void dfs_construct(int v, std::string&, std::vector<std::string>&, int limit);
};



#endif //SEARCHENGINE_H
