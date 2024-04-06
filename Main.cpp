#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "src/Trie/Trie.h"
#include <vector>

std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    Trie trie;

    // dictionary.txt dosyasını oku ve Trie'ye ekle
    std::ifstream dictionaryFile("../dictionary.txt");
    if (!dictionaryFile.is_open()) {
        std::cerr << "dictionary.txt could not be opened!" << std::endl;
        return 1;
    }

    int wordCount;
    dictionaryFile >> wordCount; // İlk satırdaki kelime sayısını oku

    std::string word;
    for (int i = 0; i < wordCount; ++i) {
        dictionaryFile >> word;
        trie.insert(word);
    }

    dictionaryFile.close(); // Dosyayı kapat

    // input.txt dosyasını oku ve her bir satırı işle
    std::ifstream inputFile("../input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "input.txt could not be opened!" << std::endl;
        return 1;
    }

    // output.txt dosyasını mevcut dizine (main.cpp'nin bulunduğu dizin) kaydet
    std::string outputPath = "../output.txt";
    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open()) {
        std::cerr << outputPath << " could not be created!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line); // İlk satırı oku (komut sayısını al)
    int commandCount = std::stoi(line); // Komut sayısını integer'a dönüştür

    for (int i = 0; i < commandCount; ++i) {
        std::getline(inputFile, line);
        std::vector<std::string> tokens = split(line, ' ');
        if (tokens.size() < 2) {
            std::cerr << "invalid entry: " << line << std::endl;
            continue;
        }

        if (tokens[0] == "search") {
            std::string wordToSearch = tokens[1];
            bool result = trie.search(wordToSearch);
            outputFile << (result ? "true" : "false") << std::endl;
        } else if (tokens[0] == "prefix") {
            std::string prefix = tokens[1];
            trie.prefix(prefix, outputFile);
            outputFile << std::endl;
        } else {
            std::cerr << "invalid command: " << tokens[0] << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
