#include <iostream>
#include <cctype>

// Explain wanted arguments for program execution
void explain_args(char* prog_name) {
    cerr << "Usage: " << prog_name
        << "\n -i Average number of successive process arrivals,"
        << "\n -k Average process lifespan" << endl;
}


// Returns -1 in case of error
int get_line_id(char* line) {
    int pos = 0;
    int id = atoi(line[pos]);
    pos++;
    while (!isspace(line[pos])) {
        if (line[pos] >= '0' && line[pos] <= '9') {
            id = id*10 + atoi(line[pos]);
            pos++;
        }
        else 
            return -1;
    }
    return id;
}

char* get_pure_doc(char* line) {
    int pos = 0;
    // Id chars
    while (!isspace(line[pos]))
        pos++;
    // Whitespace after id
    while (isspace(line[pos]))
        pos++;
        
    return &line[pos];
}