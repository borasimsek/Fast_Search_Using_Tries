// Trie.cpp

#include <iostream>
#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string& word) const {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            return false;
        }
        current = current->children[index];
    }
    return (current != nullptr && current->isEndOfWord);
}

void Trie::prefix(const std::string& prefix, std::ostream& outputFile) const {
    TrieNode* current = root;
    std::string currentWord = "";
    // İlk önce prefix'in olduğu yere ilerle
    for (char c : prefix) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            std::cout << "Prefix bulunamadi." << std::endl;
            return;
        }
        currentWord += c;
        current = current->children[index];
    }
    // Şimdi prefix'in altındaki kelimeleri bul
    prefixHelper(current, currentWord, prefix, outputFile);
}

void Trie::prefixHelper(TrieNode* node, std::string currentWord, const std::string& prefix, std::ostream& outputFile) const {
    if (node == nullptr) {
        return;
    }
    if (node->isEndOfWord) {
        std::cout << currentWord << " "; // Konsola yaz
        outputFile << currentWord << " "; // Dosyaya yaz
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i] != nullptr) {
            char nextChar = 'a' + i;
            prefixHelper(node->children[i], currentWord + nextChar, prefix, outputFile);
        }
    }
}
