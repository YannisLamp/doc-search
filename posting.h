#ifndef SYSPRO_PROJECT_1_POSTING_H
#define SYSPRO_PROJECT_1_POSTING_H

/*
 * Posting class
 * As a node, it stores a document id and how many times the word
 * of the TrieNode that leads to it is found in the document (count)
 * It points to the next Posting,
 * Only has setter and getter methods, as all PostingList tasks are handled by the head (PostingList)
 */

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