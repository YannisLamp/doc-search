#include <iostream>
#include "posting_list_node.h"

using namespace std;


PostingListNode::PostingListNode(int doc_id) : id(doc_id), count(1),
                                                    next_ptr(NULL) {
	cout << "Creating PostingListNode" << endl;
}


PostingListNode::~PostingListNode() {
	cout << "Deleting PostingListNode" << endl;
	delete next_ptr;
}


void PostingListNode::incr_count() {
    count++;
}


void PostingListNode::set_next_ptr(PostingListNode* input_ptr) {
    next_ptr = input_ptr;
}


int PostingListNode::get_id() {
    return id;
}


int PostingListNode::get_count() {
    return count;
}


PostingListNode* PostingListNode::get_next_ptr() {
    return next_ptr;
}
