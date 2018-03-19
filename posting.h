#ifndef SYSPRO_PROJECT_1_POSTING_H
#define SYSPRO_PROJECT_1_POSTING_H


class Posting {
private:
    int id;
    int count;

    Posting* next_ptr;
public:
    Posting(int doc_id);
    ~Posting();

    void incr_count();
    void set_next_ptr(Posting* input_ptr);

    int get_id();
    int get_count();
    Posting* get_next_ptr();
};

#endif