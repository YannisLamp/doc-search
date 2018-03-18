cmake_minimum_required(VERSION 3.8)
project(SysPro_Project_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        posting.cpp
        posting.h
        posting_list.cpp
        posting_list.h
        trie.cpp
        trie.h
        trie_node.cpp
        trie_node.h
        utils.cpp
        utils.h query_result.cpp query_result.h quicksort.cpp quicksort.h)

add_executable(SysPro_Project_1 ${SOURCE_FILES})