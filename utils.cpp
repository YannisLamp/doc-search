#include <iostream>
#include <cctype>

// Explain wanted arguments for program execution
void explain_args(char* prog_name) {
    cerr << "Usage: " << prog_name
        << "\n -i Average number of successive process arrivals, (mandatory)"
        << "\n -k Average process lifespan (proeretiko)" << endl;
}


// Returns -1 in case of error
int get_line_id(char* doc) {
    int pos = 0;
    // Ignore whitespace at the start of the document
    while (isspace(doc[pos]))
        pos++;
    
    // Get each digit of the id 
    int id = atoi(doc[pos]);
    pos++;
    while (!isspace(doc[pos])) {
        if (doc[pos] >= '0' && doc[pos] <= '9') {
            id = id*10 + atoi(doc[pos]);
            pos++;
        }
        // Error, not a number, return -1
        else 
            return -1;
    }
    return id;
}

char* get_pure_doc(char* doc) {
    int pos = 0;
    // Id chars
    while (!isspace(doc[pos]))
        pos++;
    // Whitespace after id
    while (isspace(doc[pos]))
        pos++;
    return &doc[pos];
}

void alloc_chk(void* alloc_ptr, char* msg) {
    if (alloc_ptr == NULL) {
        cerr << "Memory allocation for " << msg << " failed" << endl;
        exit(-1);
    }
}

