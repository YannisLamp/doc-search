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
    char map_str[] = "map";
    alloc_chk(map, map_str);
    // The number of words in each document saved in the map
    int* word_num = (int*)malloc(map_size*sizeof(int));
    char word_num_str[] = "word_num";
    alloc_chk(word_num, word_num_str);
    
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
        int doc_index = 0;

        // Consume whitespace at the start of the document
        while (isspace(line[doc_index]) && line[doc_index] != '\n')
            doc_index++;
        // If next char is not a line change (document is not empty)
        if (line[doc_index] != '\n') {

            // Check if input documents are properly numbered
            int input_id = get_doc_id(line);
            if (input_id != doc_id) {
                cerr << "Input documents are not properly numbered" << endl;
                return 1;
            }

            // If map is full, realloc
            if (input_id == map_size - 1) {
                map_size = map_size * 2;
                realloc(map, map_size * sizeof(char *));
                alloc_chk(map, map_str);

                realloc(word_num, map_size * sizeof(int));
                alloc_chk(word_num, word_num_str);
            }

            // Save current document word number (get_word_num counts id too)
            word_num[doc_id] = get_word_num(line) - 1;
            doc_index = get_next_word_index(line , doc_index);
            // Count document size
            int doc_size = 0;
            while (line[doc_index + doc_size] != '\n')
                doc_size++;
            // Allocate space for document (plus '\0')
            map[doc_id] = (char *) malloc((doc_size+1) * sizeof(char));
            alloc_chk(map, map_str);
            // Save document in map
            strncpy(map[doc_id], &line[doc_index], doc_size);
            map[doc_id][doc_size] = '\0';

            // Insert each word of the document into Trie
            for (int i = 0; i < word_num[doc_id]; i++) {
                trie.insert(&line[doc_index], doc_id);\
                doc_index = get_next_word_index(line , doc_index);
            }
            int a =0;
        }
    }
    // Check if the input file is empty (program did not enter the while loop)
    if (doc_id == -1) {
        cerr << "Input file is empty" << endl;
        exit(-1);
    }


    //trie.print_doc_freq();

    /** 
    * 
    */

    bool exit_prog = false;
    while (exit_prog == false) {
        read = getline(&line, &len, stdin);
        // Check for errors in getline
        if (read == -1) {

        }




    }









    // Delete Trie


    // Free input document map
    //for (int i = 0; i < ; i++)
        //free()

    // fclose



























    // Free line buffer
    free(line);
    line = NULL;

}




