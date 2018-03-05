#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "utils.h"
#include "trie_node.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    // Check program arguments and assign them to proper variables


    char* docfile = nullptr;
    int K = 10;
    for (int i = 1; i < argc)


    if (argc == 5) {
        if (strcmp(argv[1], "-i")) {
            docfile = argv[2];
            if (strcmp(argv[3], "-k")
                K = atoi(argv[4]);
            else {
                explain_args();
                return 1;
            }
        }
        else if (strcmp(argv[1], "-k") {
            K = atoi(argv[2]);
            if (strcmp(argv[3], "-i")
                docfile = argv[4];
            else {
                explain_args();
                return 1;
            }
        }
        else {
            explain_args();
            return 1;
        }
    }
    else if (argc == 3) {
        if (strcmp(argv[1], "-i")
            docfile = argv[4];
        else {
            explain_args();
            return 1;
        }
    }
    else {
        explain_args();
        return 1;
    }
    


    /** 
    * Parse docfile
    */

    // Open input document file
    FILE* docfile_ptr = fopen(docfile, "r");
    if (docfile_ptr == NULL) {
        cerr << "File " << docfile << " could not be opened" << endl;
        return 1; 
    }

    char* line = nullptr;
    size_t len = 0;
    ssize_t read = 0;

    // Input map
    int map_size = 32;
    char** map = malloc(map_size*sizeof(char*));
    
    
    // Get first line
    read = getline(&line, &len, docfile_ptr);
    if (read == -1) {
        cerr << "Input file is empty" << endl;
        return 1;
    }


    // For each line of the input file
    // https://linux.die.net/man/3/getline
    curr_doc = 1;
    while ((read = getline(&line, &len, docfile_ptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
        
        // Check if input documents are properly numbered
        int doc_id = get_doc_id(line);
        if (doc_id != curr_doc) {
            cerr << "Input documents are not properly numbered" << endl;
            return 1;
        }

        // Map full of documents, realloc
        if (doc_id == map_size - 1) {
            map_size = map_size*2;
            realloc(map, map_size*sizeof(char*));
        }

        char* pure_doc = get_pure_doc(line);
        map[doc_id] = malloc(sizeof(pure_doc));
        strcpy(map[doc_id], pure_doc);

        curr_doc++;
    }

    // Free line buffer
    free(line);

    
    /** 
    * Initialize Trie and insert each word in map into it
    */

    for (int i = 0; i < map_size; i++) {
        
    }







    
}
