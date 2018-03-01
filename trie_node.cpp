#include <iostream>
#include "trie_node.h"

using namespace std;

TrieNode::TrieNode(Process* input_ptr) : process_ptr(input_ptr), nextnode_ptr(nullptr), 
									 prevnode_ptr(nullptr) {
	cout << "Creating TrieNode" << endl;
};

TrieNode::~TrieNode() {
	cout << "Deleting TrieNode" << endl;
	delete process_ptr;
};

void TrieNode::set_nextnode(TrieNode* input_ptr) {
	nextnode_ptr = input_ptr;
}

void TrieNode::set_prevnode(TrieNode* input_ptr) {
	prevnode_ptr = input_ptr;
}

Process* TrieNode::get_process() {
	return process_ptr;
}

TrieNode* TrieNode::get_nextnode() {
	return nextnode_ptr;
}

TrieNode* TrieNode::get_prevnode() {
	return prevnode_ptr;
}
