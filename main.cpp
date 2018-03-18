#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "utils.h"
#include "trie.h"
#include "posting.h"
#include "query_result.h"
#include "query_quicksort.h"
#include <cmath>

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
    * Insert every input word into Trie
    */

    // Open input document file
    FILE* docfile_ptr = fopen(docfile, "r");
    if (docfile_ptr == NULL) {
        cerr << "File " << docfile << " could not be opened" << endl;
        exit(-1); 
    }

    // Input document map
    int map_size = 32;
    char** map = (char**)malloc(map_size*sizeof(char*));;
    alloc_chk(map);
    // The number of words in each document saved in the map
    int* map_word_num = (int*)malloc(map_size*sizeof(int));
    alloc_chk(map_word_num);
    
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

        // Pass whitespace at the start of the document
        while (isspace(line[doc_index]))
            doc_index++;
        // If next char is not '\0' (document is not empty)
        if (line[doc_index] != '\0') {

            // Check if input documents are properly numbered
            int input_id = atoi(line);
            if (input_id != doc_id) {
                cerr << "Input documents are not properly numbered" << endl;
                return 1;
            }

            // If map is full, realloc
            if (input_id == map_size - 1) {
                map_size = map_size * 2;
                map = (char**)realloc(map, map_size * sizeof(char *));
                alloc_chk(map);

                map_word_num = (int*)realloc(map_word_num, map_size * sizeof(int));
                alloc_chk(map_word_num);
            }

            // Save current document word number (get_word_num counts id too)
            map_word_num[doc_id] = get_word_num(line) - 1;
            doc_index = get_next_word_index(line , doc_index);
            // Count document size
            int doc_len = strlen(&line[doc_index]);
            // Allocate space for document (plus '\0')
            if (line[doc_index + doc_len] == '\n')
                line[doc_index + doc_len] = ' ';

            map[doc_id] = (char *) malloc((doc_len+1) * sizeof(char));
            alloc_chk(map[doc_id]);
            // Save document in map
            strcpy(map[doc_id], &line[doc_index]);

            // Insert each word of the document into Trie
            for (int i = 0; i < map_word_num[doc_id]; i++) {
                trie.insert(&line[doc_index], doc_id);
                doc_index = get_next_word_index(line , doc_index);
            }
        }
    }
    // Check if the input file is empty (program did not enter the while loop)
    if (doc_id == -1) {
        cerr << "Input file is empty" << endl;
        exit(-1);
    }


    /**
    * Main program loop
    * Get and execute user commands
    */

    // Necessary data for command execution

    bool exit_prog = false;
    while (exit_prog == false) {
        read = getline(&line, &len, stdin);
        // Check for errors in getline
        if (read == -1) {

        }
        int index = 0;
        while (isspace(line[index]))
            index++;
        int input_num = get_word_num(line);
        if (input_num > 0) {
            if (strncmp(&line[index], "/df", 3) == 0) {
                if (input_num == 1) {
                    trie.print_doc_freq();
                    cout << endl;
                }
                else if (input_num == 2) {
                    index = get_next_word_index(line, index);
                    int doc_freq = trie.get_doc_freq(&line[index]);
                    // If there is a result, print it
                    if (doc_freq != -1) {
                        print_until_space(&line[index]);
                        cout << ' ' << doc_freq << endl;
                    }
                    // Else
                    else {
                        cout << "No results found for ";
                        print_until_space(&line[index]);
                        cout << endl;
                    }
                }
                // Wrong command
                else {

                }
            }
            else if (strncmp(&line[index], "/tf", 3) == 0
                    && input_num == 3) {
                index = get_next_word_index(line, index);
                int id = atoi(&line[index]);

                index = get_next_word_index(line, index);
                int term_freq = trie.get_term_freq(&line[index], id);

                // If there is a result, print it
                if (term_freq != -1) {
                    cout << id << ' ';
                    print_until_space(&line[index]);
                    cout << ' ' << term_freq << endl;
                }
                // Else
                else {
                    cout << "No results found for ";
                    print_until_space(&line[index]);
                    cout << endl;
                }
            }
            // Search command implementation
            else if (strncmp(&line[index], "/search", 7) == 0
                     && input_num <= 11) {
                // Important data for calculations
                char* comm_words[10];
                Posting* curr_posting_ptrs[10];

                for (int i = 0; i < input_num-1; i++) {
                    index = get_next_word_index(line, index);
                    comm_words[i] = &line[index];
                    if (trie.search_posting_list(&line[index]) != NULL)
                        curr_posting_ptrs[i] = trie.search_posting_list(&line[index])->get_first_node_ptr();
                    else
                        curr_posting_ptrs[i] = NULL;
                }

                int results_size = 32;
                QueryResult** results = (QueryResult**)malloc(results_size*sizeof(QueryResult*));
                alloc_chk(results);

                double k1 = 1.2;
                double b = 0.75;
                int N = doc_id+1;

                // Make calculations and save the query relativity results
                int min_id = -1;
                int result_num = 0;

                do {
                    min_id = -1;
                    for (int i = 0; i < input_num-1; i++) {
                        if (curr_posting_ptrs[i] != NULL) {
                            if (min_id == -1 || min_id > curr_posting_ptrs[i]->get_id())
                                min_id = curr_posting_ptrs[i]->get_id();
                        }
                    }

                    double curr_score = 0;
                    if (min_id != -1) {
                        for (int i = 0; i < input_num-1; i++) {
                            if (min_id == curr_posting_ptrs[i]->get_id()) {
                                int n_qi = trie.get_doc_freq(comm_words[i]);
                                // EDO PROSOXI
                                double idf = log10((N - n_qi + 0.5)/(n_qi + 0.5));
                                int f_qi = curr_posting_ptrs[i]->get_count();
                            }
                        }
                    }
                } while (min_id != -1);

                // Then sort results using quicksort, if there are any
                if (result_num > 0) {






                    // Finally print top K results or, if there are not that many,
                    // as many as possible
                    struct winzise w;
                    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
                    w.ws_col


                }
                else {
                    cout << "No results found for " << &comm_words[0] << endl;
                }








                // Free results
                for (int i = 0; i < result_num; i++)
                    delete results[i];
                free(results);
            }
            else if (strncmp(&line[index], "/exit", 5) == 0
                     && input_num == 1) {
                exit_prog = true;
            }
            // Wrong command
            else {

            }

        }
    }








    // Delete Trie


    // Free input document map
    //for (int i = 0; i < ; i++)
        //free()

    // fclose



























    // Free line buffer
    free(line);

}




