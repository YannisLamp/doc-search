#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

// Explain wanted arguments for program execution
void explain_args(char* prog_name) {
    cerr << "Usage: " << prog_name
        << "\n -i, followed by the name of the input file (mandatory)"
        << "\n -k, followed by the maximum number of results for each query "
                "(optional, default value is 10, must be greater than 0)" << endl;
}


// Returns -1 in case of error, stops at first whitespace instead of '\0' (atoi)
int get_doc_id(char* str_id) {
    int pos = 0;
    // Get each digit of the id 
    int id = atoi(&str_id[pos]);
    pos++;
    while (!isspace(str_id[pos])) {
        if (str_id[pos] >= '0' && str_id[pos] <= '9') {
            id = id*10 + atoi(&str_id[pos]);
            pos++;
        }
        // Error, not a number, return -1
        else 
            return -1;
    }
    return id;
}


int get_word_num(char* doc) {
    int word_num = 0;
    int i = 0;
    // Ignore starting whitespace
    while (isspace(doc[i]) && doc[i] != '\0')
        i++;

    while (doc[i] != '\0') {
        // If we found a word, pass it
        if (!isspace(doc[i])) {
            word_num++;
            while (!isspace(doc[i]) && doc[i] != '\0')
                i++;
        }
        // Then pass all whitespaces except '\n'
        while (isspace(doc[i]) && doc[i] != '\0')
            i++;
    }
    return word_num;
}


int get_next_word_index(char* doc, int index) {
    // Pass current word
    while (!isspace(doc[index]))
        index++;
    // Then pass any whitespace after it
    while (isspace(doc[index]) && doc[index] != '\0')
        index++;

    return index;
}


void alloc_chk(void* alloc_ptr, char* msg) {
    if (alloc_ptr == NULL) {
        cerr << "Memory allocation for " << msg << " failed" << endl;
        exit(-1);
    }
}