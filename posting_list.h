#ifndef SYSPRO_PROJECT_1_POSTINGLIST_H
#define SYSPRO_PROJECT_1_POSTINGLIST_H

#include "posting.h"

/*
 * Main PostingList class, a single-linked list
 * Works as a head
 * It points to a Posting object (the first one)
 * To make inserts faster, it also points to the last Posting
 * Handles all main tasks of the PostingList
 */

class PostingList {
private:
    int node_num;

    Posting* first_node_ptr;
    Posting* last_node_ptr;
public:
    PostingList(int doc_id);
	~PostingList();

    void insert_doc_id(int doc_id);

    int get_node_num();
    int search_count(int id);
    Posting* get_first_node_ptr();
};







#endif