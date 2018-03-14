#ifndef TRIE
#define TRIE

#include "trie_node.h"

class Trie {
private:
    TrieNode* first_p;

    void rec_trav_down(char* word, TrieNode* trie_node_p);
    void rec_horiz_sort(char* word, TrieNode* trie_node_p);
public:
    Trie();
	~Trie();

    void insert(char* word);



};







#endif