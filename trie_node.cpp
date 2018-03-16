#include <iostream>
#include "trie_node.h"
#include "posting_list.h"

using namespace std;

TrieNode::TrieNode(char input_letter) : letter(input_letter), posting_list_ptr(NULL), 
										right_ptr(NULL), down_ptr(NULL) {
	cout << "Creating TrieNode" << endl;
}


TrieNode::~TrieNode() {
	cout << "Deleting TrieNode" << endl;
	delete posting_list_ptr;
	delete right_ptr;
	delete down_ptr;
}


void TrieNode::set_posting_list_ptr(PostingList* input_ptr) {
	posting_list_ptr = input_ptr;
}


void TrieNode::set_right_ptr(TrieNode* input_ptr) {
	right_ptr = input_ptr;
}


void TrieNode::set_down_ptr(TrieNode* input_ptr) {
	down_ptr = input_ptr;
}


char TrieNode::get_letter() {
	return letter;
}


PostingList* TrieNode::get_posting_list_ptr() {
	return posting_list_ptr;
}


TrieNode* TrieNode::get_right_ptr() {
	return right_ptr;
}


TrieNode* TrieNode::get_down_ptr() {
	return down_ptr;
}