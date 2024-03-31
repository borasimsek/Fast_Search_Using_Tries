//
// Created by bora on 31.03.2024.
//

#ifndef CS_201_PROJECT2_TRIE_H
#define CS_201_PROJECT2_TRIE_H

#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;


struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        children.resize(26, nullptr); // Alfabetik karakterler için 26 çocuk düğüm oluştur
    }
};
// Trie sınıfı
class Trie {
private:
    TrieNode* root;

public:
    // Yapıcı fonksiyon
    Trie() {
        root = new TrieNode();
    }

    // Kelimeyi Trie'ye ekleme işlevi
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr)
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isEndOfWord = true; // Kelimenin sonunu işaretle
    }

    // Kelimenin Trie'de bulunup bulunmadığını kontrol etme işlevi
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return (current != nullptr && current->isEndOfWord); // Kelime sonu bayrağı kontrolü
    }
};

#endif //CS_201_PROJECT2_TRIE_H
