#ifndef SYSPRO_PROJECT_1_TRIENODE_H
#define SYSPRO_PROJECT_1_TRIENODE_H

#include "posting_list.h"

/*
 * TrieNode class
 * As a node, it stores a letter and pointers to a possible PostingList,
 * a down and a right TrieNode
 * Only has setter and getter methods, as all Trie tasks are handled by the head (Trie)
 */

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
