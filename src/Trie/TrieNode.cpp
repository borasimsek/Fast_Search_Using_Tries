//
// Created by bora on 6.04.2024.
//

#include "TrieNode.h"

TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        children[i] = nullptr;
    }
    isEndOfWord = false;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        delete children[i];
    }
}