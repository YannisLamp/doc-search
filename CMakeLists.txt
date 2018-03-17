cmake_minimum_required(VERSION 3.9)
project(SysPro_Project_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(SysPro_Project_1
        main.cpp
        posting_list.cpp
        posting_list.h
        posting.cpp
        posting.h
        trie.cpp
        trie.h
        trie_node.cpp
        trie_node.h
        utils.cpp
        utils.h)
