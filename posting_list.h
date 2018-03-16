#ifndef POSTINGLIST
#define POSTINGLIST

#include "posting.h"

class PostingList {
private:
    char* word;
    int node_num;

    Posting* first_node_ptr;
    Posting* last_node_ptr;
public:
    PostingList(char* input_word, int doc_id);
	~PostingList();

    void insert_doc_id(int doc_id);

    int get_node_num();
    char* get_word();
};







#endif