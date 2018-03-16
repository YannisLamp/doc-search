#include <iostream>
#include "trie.h"
#include "trie_node.h"

using namespace std;


Trie::Trie() : first_p(NULL) {
	cout << "Creating Trie" << endl;
}


Trie::~Trie() {
	cout << "Deleting Trie" << endl;
	delete first_p;
}


void Trie::rec_insert(char* word, TrieNode* curr_node_p, int doc_id) {
	// If the current letter of the word is equal to the letter of
	// the current Trie node
	if (word[0] == curr_node_p->get_letter()) {
		// If its the last letter of the word then add toPOSTING
		if (isspace(word[1]) || word[1] == '\0') {

		}
		else if (curr_node_p->get_down_p() == NULL) {
			curr_node_p->set_down_p(new TrieNode(word[1]));
		}
		// If 
		else if (word[0] < curr_node_p->get_down_p()->get_letter()) {

		}
		else {

		}

	}
	// Else
	else { 
	
		if (curr_node_p->get_right_p() == NULL) {


		}
		else if (word[0] < curr_node_p->get_right_p()->get_letter()) {

		}
		else {
			rec_insert(word, curr_node_p->get_right_p());
		}

	}

}


void Trie::insert(char* word, int doc_id) {
	// Only manage first_p here, rest is done in rec_insert
	if (first_p == NULL) {
		first_p = new TrieNode(word[0]);
		rec_insert(word, first_p, doc_id);
	}
	else if (word[0] < first_p->get_letter()) {
		TrieNode* temp_node_p = first_p;
		first_p = new TrieNode(word[0]);
		first_p->set_right_p(temp_node_p);
		rec_insert(word, first_p, doc_id);
	}
	else {
		rec_insert(word, first_p, doc_id);
	}
}