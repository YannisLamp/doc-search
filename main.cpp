#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "utils.h"
#include "trie_node.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    // Check program arguments and assign them to proper variables
    char* docfile = NULL;
    int K = 10;
    // For this particular program
    for (int argp = 1; argp < argc; argp = argp + 2) {
        if (strcmp(argv[argp], "-i"))
            docfile = argv[argp + 1];
        else if (strcmp(argv[argp], "-k"))
            K = atoi(argv[argp + 1]);
        // Else explain wanted arguments for program execution and terminate
        else {
            cerr << "Usage: " << prog_name
                << "\n -i Average number of successive process arrivals,"
                << "\n -k Average process lifespan" << endl;
            // AUTO????????????
            exit(-1);
        }
    }
    // Check if a value is assigned to docfile (name of the input file)
    // If it is, terminate
    if (docfile === NULL) {
        
    } 


    

    /** 
    * Parse docfile
    * Initialize Trie and insert each word in map into it
    */

    // Open input document file
    FILE* docfile_ptr = fopen(docfile, "r");
    if (docfile_ptr == NULL) {
        cerr << "File " << docfile << " could not be opened" << endl;
        exit(-1); 
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    // Input map
    int map_size = 32;
    char** map = malloc(map_size*sizeof(char*));
    alloc_chk(map, "map");
    
    // Initialize Trie
    

    // Get first line
    read = getline(&line, &len, docfile_ptr);
    if (read == -1) {
        cerr << "Input file is empty" << endl;
        exit(-1);
    }
    else {
        
    }


    // For each line of the input file
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
            alloc_chk(map, "map");    
        }

        char* pure_doc = get_pure_doc(line);
        // Insert each word of the document into Trie

        curr_doc++;
    }

    // Free line buffer
    free(line);

    
    /** 
    * 
    */

    for (int i = 0; i < map_size; i++) {
        
    }







    
}
