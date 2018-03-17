#ifndef SYSPRO_PROJECT_1_POSTINGLIST_H
#define SYSPRO_PROJECT_1_POSTINGLIST_H

#include "posting.h"

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
};







#endif