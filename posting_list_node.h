#ifndef POSTINGLISTNODE
#define POSTINGLISTNODE

class PostingListNode {
private:
    int id;
    int count;

    PostingListNode* next_ptr;
public:
    PostingListNode(int doc_id);
    ~PostingListNode();

    void incr_count();
    void set_next_ptr(PostingListNode* input_ptr);

    int get_id();
    int get_count();
    PostingListNode* get_next_ptr();
};

#endif