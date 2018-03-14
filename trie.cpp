#include <iostream>
#include "trie.h"
#include "trie_node.h"

using namespace std;

// Consume a character
Trie::rec_trav_down(char* word, trie_node_p) {

}


Trie::rec_trav_right(char* word, TrieNode* trie_node_p) {
	if (word[0] > trie_node_p->get_letter()) {

	}
}


Trie::Trie() : first_p(NULL) {
	cout << "Creating Trie" << endl;
}


Trie::~Trie() {
	cout << "Deleting Trie" << endl;
	delete first_p;
}


void Trie::insert(char* word) {
	// Only manage first_p here, rest is done in rec_insert
	if (first_p == NUll) {
		first_p = new TrieNode();
		rec_trav_down(word+1, first_p);
	}
	else {
		rec_horiz_sort(word, first_p);
	}
}