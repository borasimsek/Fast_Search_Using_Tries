// Trie.h

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <iostream> // std::ostream için

const int ALPHABET_SIZE = 26; // ALPHABET_SIZE sabiti tanımlanıyor

class TrieNode {
public:
    TrieNode();
    ~TrieNode();

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
    bool search(const std::string& word) const;
    void prefix(const std::string& prefix, std::ostream& outputFile) const;
    void prefixHelper(TrieNode* node, std::string currentWord, const std::string& prefix, std::ostream& outputFile) const;
};

#endif // TRIE_H
