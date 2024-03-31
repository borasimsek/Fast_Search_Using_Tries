//
// Created by bora on 30.03.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include "src/Trie/Trie.h"
#include "src/Trie/TrieNode.h"


void buildTrieFromFile(Trie& trie, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }

    int numWords;
    file >> numWords; // Read the number of words

    std::string word;
    for (int i = 0; i < numWords; ++i) {
        file >> word;
        trie.insert(word); // Insert the word into the Trie
    }

    file.close();
}

int main() {
    /*
    // Open input.txt for reading
    std::ifstream inputFile("src/input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input.txt for reading!" << std::endl;
        return 1;
    }

    // Open output.txt for writing
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output.txt for writing!" << std::endl;
        return 1;
    }

    int numLines;
    inputFile >> numLines; // Read the number of lines from the first row

    std::string line;
    std::getline(inputFile, line); // Consume the newline character after the first row

    // Read and write the specified number of lines
    for (int i = 0; i < numLines; ++i) {
        std::getline(inputFile, line); // Read a line from input.txt
        outputFile << line << std::endl; // Write the line to output.txt
    }

    // Close files
    inputFile.close();
    outputFile.close();

    std::cout << "Data has been copied to output.txt." << std::endl;

    */
    Trie trie;
    buildTrieFromFile(trie, "Dictionary.txt");
    if (trie.search("ace"))
        std::cout << "Word 'ace' found in the dictionary." << std::endl;
    else
        std::cout << "Word 'ace' not found in the dictionary." << std::endl;

    return 0;
}
