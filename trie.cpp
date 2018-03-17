#include <iostream>
#include <cstring>
#include "trie.h"

#include "trie_node.h"

using namespace std;


Trie::Trie() : first_ptr(NULL) { }


Trie::~Trie() { delete first_ptr; }


void Trie::rec_insert(char* word, TrieNode* curr_node_ptr, int doc_id) {
	// If the current letter of the word is equal to the letter of
	// the current Trie node, then
	if (word[0] == curr_node_ptr->get_letter()) {
		// If its the last letter of the word then end recursion
		if (isspace(word[1]) || word[1] == '\0') {
            // If there is no posting list in this node then make one, then insert the document id
            if (curr_node_ptr->get_posting_list_ptr() == NULL)
			    curr_node_ptr->set_posting_list_ptr(new PostingList(doc_id));
            // Else just insert the document id into the existing posting list
            else
                curr_node_ptr->get_posting_list_ptr()->insert_doc_id(doc_id);
		}
		else { 
			if (curr_node_ptr->get_down_ptr() == NULL) {
				curr_node_ptr->set_down_ptr(new TrieNode(word[1]));
				rec_insert(&word[1], curr_node_ptr->get_down_ptr(), doc_id);
			}
			// If 
			else if (word[1] < curr_node_ptr->get_down_ptr()->get_letter()) {
				TrieNode* temp_ptr = new TrieNode(word[1]);
				temp_ptr->set_right_ptr(curr_node_ptr->get_down_ptr());
				curr_node_ptr->set_down_ptr(temp_ptr);
				rec_insert(&word[1], curr_node_ptr->get_down_ptr(), doc_id);
			}
			else {
				rec_insert(&word[1], curr_node_ptr->get_down_ptr(), doc_id);
			}
		}
	}
	// Else
	else { 
	
		if (curr_node_ptr->get_right_ptr() == NULL) {
			curr_node_ptr->set_right_ptr(new TrieNode(word[0]));
			rec_insert(word, curr_node_ptr->get_right_ptr(), doc_id);
		}
		else if (word[0] < curr_node_ptr->get_right_ptr()->get_letter()) {
			TrieNode* temp_ptr = new TrieNode(word[0]);
			temp_ptr->set_right_ptr(curr_node_ptr->get_right_ptr());
			curr_node_ptr->set_right_ptr(temp_ptr);
			rec_insert(word, curr_node_ptr->get_right_ptr(), doc_id);
		}
		else {
			rec_insert(word, curr_node_ptr->get_right_ptr(), doc_id);
		}
	}
}


void Trie::insert(char* word, int doc_id) {
	// Only manage first_ptr here, rest is done in rec_insert
	if (first_ptr == NULL) {
		first_ptr = new TrieNode(word[0]);
		rec_insert(word, first_ptr, doc_id);
	}
	else if (word[0] < first_ptr->get_letter()) {
		TrieNode* temp_node_ptr = first_ptr;
		first_ptr = new TrieNode(word[0]);
		first_ptr->set_right_ptr(temp_node_ptr);
		rec_insert(word, first_ptr, doc_id);
	}
	else {
		rec_insert(word, first_ptr, doc_id);
	}
}

void Trie::print_doc_freq() {
    //char empty_str[] = "";
    rec_print_doc_freq(first_ptr, "");
}

void Trie::rec_print_doc_freq(TrieNode* curr_node_ptr, char* curr_word) {
    char word[sizeof(curr_word) + 1];
    strcpy(word, curr_word);
    word[strlen(curr_word)] = curr_node_ptr->get_letter();
    word[strlen(curr_word) + 1] = curr_node_ptr->get_letter();

    if (curr_node_ptr->get_posting_list_ptr() != NULL)
        cout << word << " " << curr_node_ptr->get_posting_list_ptr()->get_node_num();

    if (curr_node_ptr->get_down_ptr() != NULL)
        rec_print_doc_freq(curr_node_ptr->get_down_ptr(), word);

    if (curr_node_ptr->get_right_ptr() != NULL)
        rec_print_doc_freq(curr_node_ptr->get_right_ptr(), word);
}