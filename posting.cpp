#include <iostream>
#include "posting.h"

using namespace std;


Posting::Posting(int doc_id) : id(doc_id), count(1),
                                                    next_ptr(NULL) {
}


Posting::~Posting() {
	delete next_ptr;
}


void Posting::incr_count() {
    count++;
}


void Posting::set_next_ptr(PostingListNode* input_ptr) {
    next_ptr = input_ptr;
}


int Posting::get_id() {
    return id;
}


int Posting::get_count() {
    return count;
}


Posting* Posting::get_next_ptr() {
    return next_ptr;
}
