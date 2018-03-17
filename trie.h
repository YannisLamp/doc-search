#ifndef TRIE
#define TRIE

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