#include <iostream>
#include "posting_list.h"
#include "posting.h"


using namespace std;

PostingList::PostingList(int doc_id) : node_num(1) {
	first_node_ptr = new Posting(doc_id);
    last_node_ptr = first_node_ptr;
}


PostingList::~PostingList() { delete first_node_ptr; }


// Inserts a document id, the use of a pointer to the last Posting
// makes it very fast, because the input documents
// are sorted by id
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


// Searches the list for the give id, then returns count
int PostingList::search_count(int id) {
    Posting* curr_posting = first_node_ptr;
    while (curr_posting != NULL && id > curr_posting->get_id()) {
        curr_posting = curr_posting->get_next_ptr();
    }
    if (curr_posting != NULL && id == curr_posting->get_id())
        return curr_posting->get_count();
    else
        return -1;
}

Posting* PostingList::get_first_node_ptr() { return first_node_ptr; }