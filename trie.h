#ifndef SYSPRO_PROJECT_1_TRIE_H
#define SYSPRO_PROJECT_1_TRIE_H

#include "trie_node.h"
#include "posting_list.h"

class Trie {
private:
    TrieNode* first_ptr;

    void rec_insert(char* word, TrieNode* curr_node_ptr, int doc_id);
    void rec_print_doc_freq(TrieNode* curr_node_ptr, char** word,
                            int* size, int curr_len);
    PostingList* rec_search_posting_list(char* word, TrieNode* curr_node);
public:
    Trie();
	~Trie();

    void insert(char* word, int doc_id);
    void print_doc_freq();
    PostingList* search_posting_list(char* word);
    int get_doc_freq(char* word);
	int get_term_freq(char* word, int id);
};







#endif