#ifndef POSTINGLIST
#define POSTINGLIST

#include "posting_list_node.h"

class PostingList {
private:
    int node_num;

    PostingListNode* first_node_ptr;
    PostingListNode* last_node_ptr;
public:
    PostingList(int doc_id);
	~PostingList();

    void insert_doc_id(int doc_id);

    int get_node_num();
};







#endif