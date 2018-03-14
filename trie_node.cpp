#include <iostream>
#include "trie_node.h"

using namespace std;

TrieNode::TrieNode(char input) : letter(input), right_p(NULL), 
									down_p(NULL) {
	cout << "Creating TrieNode" << endl;
}


TrieNode::~TrieNode() {
	cout << "Deleting TrieNode" << endl;
	delete right_p;
	delete down_p;
}


void TrieNode::set_right_p(TrieNode* input_p) {
	right_p = input_p;
}


void TrieNode::set_down_p(TrieNode* input_p) {
	down_p = input_p;
}


char TrieNode::get_letter() {
	return letter;
}


TrieNode* TrieNode::get_right_p() {
	return right_p;
}


TrieNode* TrieNode::get_down_p() {
	return down_p;
}