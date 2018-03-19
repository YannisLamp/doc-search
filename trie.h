#ifndef SYSPRO_PROJECT_1_TRIE_H
#define SYSPRO_PROJECT_1_TRIE_H

#include "trie_node.h"
#include "posting_list.h"

/*
 * Main Trie class
 * Works as a head
 * It only points to a single TrieNode object
 * Handles all main tasks of the Trie
 */

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