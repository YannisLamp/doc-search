#ifndef SYSPRO_PROJECT_1_TRIE_H
#define SYSPRO_PROJECT_1_TRIE_H

#include "trie_node.h"

class Trie {
private:
    TrieNode* first_ptr;

    void rec_insert(char* word, TrieNode* curr_node_ptr, int doc_id);
public:
    Trie();
	~Trie();

    void insert(char* word, int doc_id);
};







#endif