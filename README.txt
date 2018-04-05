System Programming
Project 1
Lamprou Ioannis sdi1400088
README

This readme is written in ASCII format, as was asked

The delivered .tar.gz contains the following files: trie.h trie_node.h posting_list.h posting.h utils.h query_result.h
query_quicksort.h, trie.cpp trie_node.cpp posting_list.cpp posting.cpp utils.cpp query_result.cpp query_quicksort.cpp
Makefile and this README.

These source files can be compiled with the command: make serts (where serts is the chosen program name)
For the program to work, an input file must be in the same directory as the program/
The program must take the name of this input file as an argument after the flag -i.
It can also take the maximum number of results it can output as an answer to a query (K) after the
flag -k, but its optional.
The program can take as many pairs of flags and inputs as you want, only keeping the last.

The program stores each document of the input file into a map, implemented with an array, also saving the number
of words of each document in another array in the process.

For the purpose of this project, the structures Trie and List were used so as to save where each
word belongs, implemented with the classes Trie, TrieNode, PostingList, Posting.
The Classes Trie and PostingList only point to nodes (TrieNode, Posting), without saving any other information
but, they handle every main task of their structure. The classes TrieNode and Posting are nodes, used to save
information, but only contain setter and getter methods, as they are managed by the heads.

Each TrieNode saves one character of a word, a possible pointer to a PostingList, and pointers to TrieNodes to
the same level and lower level. Each posting saves a document id (this document contains the word formed by the TrieNodes)
and a counter of how many times that document contains it.

In the files utils.cpp and utils.h many utility functions used in main.cpp are implemented.

All commands have been implemented for this project.
For the purpose of the command /search, in the formula BM25, log10 was used, instead of log2.
In order to represent id-relevance_score pairs, objects of the class QueryResult are used.
In order to sort these objects, a slightly changed quicksort algorithm is used, implemented inside
query_quicksort.cpp, query_quicksort.h.

Also, during the calculation of the query relevance scores, the fact that inside the PostingLists the document ids
are sorted in increasing order was used to increase performance.

No extra memory is allocated for the storing of individual words, lines or whatever other reason,
all allocated memory is freed and all objects created are deleted.
(Although there is a valgrind bug (or feature) saying that there is still reachable memory)

The project was developed in Ubuntu 16.04.
The project was tested in Ubuntu 16.04 and the pcs of the university.