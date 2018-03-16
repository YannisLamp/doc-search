#include <iostream>
#include "posting_list.h"
#include "posting.h"


using namespace std;

PostingList::PostingList(char* input_word, int doc_id) : word(input_word), node_num(1) {
	first_node_ptr = new Posting(doc_id);
    last_node_ptr = first_node_ptr;
}


PostingList::~PostingList() {
    // Free memory for storing the word, allocated in main during the Trie construction
    free(word);
	delete first_node_ptr;
}


void PostingList::insert_doc_id(int doc_id) {
    if (last_node_ptr->get_id() == doc_id)
        last_node_ptr->incr_count();
    else {
        Posting* temp_node_ptr = new Posting(doc_id);
        last_node_ptr->set_next_ptr(temp_node_ptr);
        node_num++;
        last_node_ptr = temp_node_ptr;
    }
}

    
int PostingList::get_node_num() {
    return node_num;
}

char* PostingList::get_word() {
    return word;
}