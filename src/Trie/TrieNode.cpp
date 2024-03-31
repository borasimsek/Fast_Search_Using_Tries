//
// Created by bora on 31.03.2024.
//

#define CS_201_PROJECT2_TRIENODE_H
#include <iostream>
#include <vector>
using namespace std;


struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        children.resize(26, nullptr); // Alfabetik karakterler için 26 çocuk düğüm oluştur
    }
};