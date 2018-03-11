#ifndef POSTINGLISTNODE
#define POSTINGLISTNODE

class PostingListNode {
private:
    int id;
    int num;

    PostingListNode* next_ptr;
public:
    
    
    void set_num(int input);
    void set_next_ptr(int ptr);

    int get_id();
    int get_num();
    int get_next_ptr();

};







#endif