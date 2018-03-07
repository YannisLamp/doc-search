#include <iostream>
#include "trie_node.h"

void TrieNode::set_nextnode(TrieNode* input_ptr) {
	nextnode_ptr = input_ptr;
}