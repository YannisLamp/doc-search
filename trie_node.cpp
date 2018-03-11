#include <iostream>
#include "trie_node.h"

using namespace std;

TrieNode::TrieNode(char input_letter) : letter(input letter), right_ptr(NULL), 
									 down_ptr(NULL) {
	cout << "Creating TrieNode" << endl;
};

TrieNode::~TrieNode() {
	cout << "Deleting TrieNode" << endl;
	delete right_ptr;
	delete down_ptr;
};

void TrieNode::set_right_ptr(TrieNode* input_ptr) {
	nextnode_ptr = input_ptr;
}

void TrieNode::set_prevnode(TrieNode* input_ptr) {
	prevnode_ptr = input_ptr;
}

Process* TrieNode::get_letter() {
	return letter;
}

TrieNode* TrieNode::get_right_ptr() {
	return right_ptr;
}

TrieNode* TrieNode::get_down_ptr() {
	return down_ptr;
}
