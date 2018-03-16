#include <iostream>
#include "posting_list.h"
#include "posting_list_node.h"


using namespace std;

PostingList::PostingList(int doc_id) : node_num(1) {
	first_node_ptr = new PostingListNode(doc_id);
    last_node_ptr = first_node_ptr;
    cout << "Creating PostingList" << endl;
}


PostingList::~PostingList() {
	cout << "Deleting PostingList" << endl;
	delete first_node_ptr;
}


void PostingList::insert_doc_id(int doc_id) {
    if (last_node_ptr->get_id() == doc_id)
        last_node_ptr->incr_count();
    else {
        PostingListNode* temp_node_ptr = new PostingListNode(doc_id);
        last_node_ptr->set_next_ptr(temp_node_ptr);
        last_node_ptr = temp_node_ptr;
    }
}

    
int PostingList::get_node_num() {
    return node_num;
}