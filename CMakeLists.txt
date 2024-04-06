cmake_minimum_required(VERSION 3.23)
project(CS_201_Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS_201_Project2
        Main.cpp
        src/Tree/TreeNode.cpp
        dictionary.txt
        input.txt
        src/Trie/TrieNode.cpp
        src/Trie/Trie.cpp
)
