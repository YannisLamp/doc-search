#ifndef SYSPRO_PROJECT_1_TRIENODE_H
#define SYSPRO_PROJECT_1_TRIENODE_H

#include "posting_list.h"

class TrieNode {
private:
	char letter;
	PostingList* posting_list_ptr;

	TrieNode* right_ptr;
    TrieNode* down_ptr;
public:
	TrieNode(char letter);
	~TrieNode();

	void set_posting_list_ptr(PostingList* input_ptr);
	void set_right_ptr(TrieNode*);
    void set_down_ptr(TrieNode*);

	char get_letter();
	PostingList* get_posting_list_ptr();
	TrieNode* get_right_ptr();
    TrieNode* get_down_ptr();
};

#endif
