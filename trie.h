#ifndef TRIE
#define TRIE

#include "trie_node.h"

class Trie {
private:
    TrieNode* first_p;

    void rec_insert(char* word, TrieNode* curr_node_p, int doc_id);
public:
    Trie();
	~Trie();

    void insert(char* word, int doc_id);
};







#endif