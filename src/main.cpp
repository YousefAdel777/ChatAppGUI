#include <iostream>
#include "SearchEngine.h"

int main() {
    SearchEngine searchEngine;
    searchEngine = SearchEngine();
    std::string hello = "hello";
    std::string hi = "hi";
    std::string word = "word";
    std::string car = "car";
    std::string cat = "cat";
    std::string cut = "cut";
    std::string care = "care";
    searchEngine.addWord(hello);
    searchEngine.addWord(hi);
    searchEngine.addWord(word);
    searchEngine.addWord(car);
    searchEngine.addWord(cat);
    searchEngine.addWord(cut);
    searchEngine.addWord(care);

    std::string s = "c";
    std::vector<std::string> rec = searchEngine.autoComplete(s, 6);
    for (auto c: rec) {
        std::cout << c << std::endl;
    }

    s = "h";
    rec = searchEngine.autoComplete(s, 5);
    for (auto c: rec) {
        std::cout << c << std::endl;
    }

    s = "m";
    rec = searchEngine.autoComplete(s, 5);
    for (auto c: rec) {
        std::cout << c << std::endl;
    }

    return 0;
}
