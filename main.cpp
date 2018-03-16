#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "utils.h"
#include "trie.h"

using namespace std;

int main(int argc, char* argv[]) {
    /** 
    * Check program arguments and assign them to proper variables
    */

    char* docfile = NULL;
    int K = 10;
    // For this particular program, after each flag another argument is expected
    // User can give any number of "-i" and "-k" flags, but only the last ones are saved
    for (int argi = 1; argi < argc; argi = argi+2) {
        if (strcmp(argv[argi], "-i") == 0)
            docfile = argv[argi + 1];
        else if (strcmp(argv[argi], "-k") == 0)
            K = atoi(argv[argi + 1]);
        // Else explain wanted arguments for program execution and terminate
        else {
            explain_args(argv[0]);
            exit(-1);
        }
    }
    // Check if a value is assigned to docfile (name of the input file)
    // and if K's value is greater than 0
    if (docfile == NULL || K <= 0) {
        explain_args(argv[0]);
        exit(-1);
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

    // Input document map
    int map_size = 32;
    char** map = (char**)malloc(map_size*sizeof(char*));
    alloc_chk(map, "map");
    
    // Initialize Trie
    Trie trie;

    // Getline vars
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    // For each line (document) of the input file
    int doc_id = -1;
    // Char* line gets automatically realloced by getline, if needed
    while ((read = getline(&line, &len, docfile_ptr)) != -1) {
        // Next document id should be 
        doc_id++;

        // Check if input documents are properly numbered
        int input_id = get_doc_id(line);
        if (input_id != doc_id) {
            cerr << "Input documents are not properly numbered" << endl;
            return 1;
        }

        // Map full of documents, realloc
        if (input_id == map_size - 1) {
            map_size = map_size*2;
            realloc(map, map_size*sizeof(char*));
            alloc_chk(map, "map");
        }

        // Copy document to map
        //char* pure_doc = get_pure_doc(line);
        //map[doc_id] = (char*)malloc(sizeof(pure_doc));
        //alloc_chk(map, "map");
        //strcpy(map[doc_id], pure_doc);

        // Insert each word of the document into Trie


        
    }
    // Check if the input file is empty (program did not enter the while loop)
    if (doc_id == -1) {
        cerr << "Input file is empty" << endl;
        exit(-1);
    }




    
    /** 
    * 
    */




    // Delete Trie


    // Free input document map
    //for (int i = 0; i < ; i++)
        //free()





























    // Free line buffer
    free(line);
    line = NULL;

}




