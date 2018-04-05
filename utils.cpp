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

// Explain wanted commands during program execution
void explain_commands() {
    cerr << "Acceptable commands:\n/df"
            "\n/df 'word' "
            "\n/tf id 'word'"
            "\n/search words (up to 10 'word')"
            "\n/exit" << endl;
}

// Get word number in a given string
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
        // Then pass all whitespaces except '\0'
        while (isspace(doc[i]) && doc[i] != '\0')
            i++;
    }
    return word_num;
}

// If doc[index] is the start of a word, then returned index is the
// start of the next word in the same string (doc), if it exists
int get_next_word_index(char* doc, int index) {
    // Pass current word
    while (!isspace(doc[index]))
        index++;
    // Then pass any whitespace after it
    while (isspace(doc[index]) && doc[index] != '\0')
        index++;

    return index;
}


// Performs standard malloc and realloc check, and exits
// program if they failed
void alloc_chk(void* alloc_ptr) {
    if (alloc_ptr == NULL) {
        cerr << "Memory allocation failed" << endl;
        exit(-1);
    }
}


// Prints word until it finds whitespace or the end of the input string
void print_until_space(char* word) {
    int i = 0;
    while (!isspace(word[i]) && word[i] != '\0') {
        cout << word[i];
        i++;
    }
}


// Returns the length of the input word
// (stops when it finds whitespace or end of string)
int word_len(char* word) {
    int len = 0;
    while (!isspace(word[len]) && word[len] != '\0')
        len++;
    return len;
}