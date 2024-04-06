//
// Created by bora on 6.04.2024.
//

#ifndef CS_201_PROJECT2_TRIENODE_H
#define CS_201_PROJECT2_TRIENODE_H

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode();
    ~TrieNode();

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};


#endif //CS_201_PROJECT2_TRIENODE_H
