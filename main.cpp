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
//#include <sys/ioctl.h>
#include <unistd.h>
#include <iomanip>

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
            return -1;
        }
    }
    // Check if a value is assigned to docfile (name of the input file)
    // and if K's value is greater than 0
    if (docfile == NULL || K <= 0) {
        explain_args(argv[0]);
        return -1;
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
                // Free each saved document in the map
                for (int i = 0; i < doc_id; i++)
                    free(map[i]);
                // Free input document map
                free(map);
                // Free saved document word numbers
                free(map_word_num);
                // Free line buffer
                free(line);
                return -1;
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
        // Free input document map
        free(map);
        // Free saved document word numbers
        free(map_word_num);
        // Free line buffer
        free(line);
        return -1;
    }

    /**
    * Main program loop
    * Get and execute user commands
    */

    // Necessary data for command execution
    // Calculate N and avgdl
    int N = doc_id+1;
    int all_word_num = 0;
    for(int i = 0; i < N; i++) {
        all_word_num = all_word_num + map_word_num[i];
    }
    double avgdl = (double)all_word_num/(double)N;

    bool exit_prog = false;
    while (exit_prog == false) {
        read = getline(&line, &len, stdin);
        // Check for errors in getline
        if (read == -1) {
            cerr << "Getline error, exit" << endl;
            // Free each saved document in the map
            for (int i = 0; i < N; i++)
                free(map[i]);
            // Free input document map
            free(map);
            // Free saved document word numbers
            free(map_word_num);
            // Free line buffer
            free(line);
            return -1;
        }
        // Consume whitespace from input
        int index = 0;
        while (isspace(line[index]))
            index++;
        int input_num = get_word_num(line);
        if (input_num > 0) {
            // Df command implementation
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
                    // Else no results found
                    else {
                        print_until_space(&line[index]);
                        cout << ' ' << 0 << endl;
                    }
                }
                // Wrong command, explain
                else {
                    explain_commands();
                }
            }
            else if (strncmp(&line[index], "/tf", 3) == 0
                    && input_num == 3) {
                index = get_next_word_index(line, index);
                int id = atoi(&line[index]);

                index = get_next_word_index(line, index);
                int term_freq = trie.get_term_freq(&line[index], id);

                // If term_freq found nothing, then result is 0
                if (term_freq == -1)
                    term_freq = 0;

                // Print results
                if (term_freq != -1) {
                    cout << id << ' ';
                    print_until_space(&line[index]);
                    cout << ' ' << term_freq << endl;
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

                // Make calculations and save the query relativity results
                int result_num = 0;
                int min_id = -1;

                do {
                    min_id = -1;
                    for (int i = 0; i < input_num-1; i++) {
                        if (curr_posting_ptrs[i] != NULL) {
                            if (min_id == -1 || min_id > curr_posting_ptrs[i]->get_id())
                                min_id = curr_posting_ptrs[i]->get_id();
                        }
                    }

                    // If there are still documents that contain the query words
                    if (min_id != -1) {
                        double curr_score = 0;
                        for (int i = 0; i < input_num-1; i++) {
                            // If this word is in the current document, calculate relativity score for that word
                            if (curr_posting_ptrs[i] != NULL && min_id == curr_posting_ptrs[i]->get_id()) {
                                int n_qi = trie.get_doc_freq(comm_words[i]);
                                double idf = log10((N - n_qi + 0.5)/(n_qi + 0.5));
                                int f_qi = curr_posting_ptrs[i]->get_count();

                                double this_doc_score = idf * ( (f_qi*(k1 + 1)) /
                                        (f_qi + k1*(1 - b + b*((double)map_word_num[min_id]/avgdl))) );

                                curr_score = curr_score + this_doc_score;

                                // Then the next posting takes this one's place
                                curr_posting_ptrs[i] = curr_posting_ptrs[i]->get_next_ptr();
                            }
                        }
                        // Realloc for results
                        result_num++;
                        if (results_size == result_num-1) {
                            results_size = results_size * 2;
                            results = (QueryResult**)realloc(results, results_size*sizeof(QueryResult*));
                            alloc_chk(results);
                        }
                        results[result_num-1] = new QueryResult(min_id, curr_score);
                    }
                } while (min_id != -1);

                // Then sort results using quicksort, and finally print them,
                // if there are any
                if (result_num > 0) {
                    query_quicksort(results, 0, result_num-1);

                    // Finally print top K results or, if there are not that many,
                    // as many as possible

                    // Get column size
                    //struct winsize win_sz;
                    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_sz);
                    //int col_num = win_sz.ws_col;

                    int col_num = 80;
                    // Find the number of results we will print
                    int res_print_num = 0;
                    if (result_num < K)
                        res_print_num = result_num;
                    else
                        res_print_num = K;

                    // Find result number digits
                    int res_print_digits = (int)floor(log10 (abs (res_print_num))) + 1;

                    // Find maximum id in results
                    int max_id = 0;
                    int neg_val = 0;
                    for (int i = 0; i < res_print_num; i++) {
                        if (results[i]->get_doc_id() > max_id)
                            max_id = results[i]->get_doc_id();
                        if (results[i]->get_rel_score() < 0)
                            neg_val = 1;
                    }
                    // Find maximum id digits
                    int max_id_digits;
                    if (max_id == 0)
                        max_id_digits = 1;
                    else
                        max_id_digits = (int)floor(log10 (abs (max_id))) + 1;

                    // Find maximum search score
                    double max_score = 0;
                    bool found_score = false;
                    for (int res_i = 0; res_i < res_print_num; res_i++) {
                        if (results[res_i]->get_rel_score() > max_score || !found_score) {
                            max_score = results[res_i]->get_rel_score();
                            found_score = true;
                        }
                    }
                    int max_score_digits;
                    if ((int)max_score == 0)
                        max_score_digits = 1;
                    else
                        max_score_digits = (int)floor(log10 (abs ((int)max_score))) + 1;

                    // Starting offset for print
                    int offset = res_print_digits + 1 + 1 + max_id_digits + 1 + 1 + neg_val
                                    + max_score_digits + 5 + 1 + 1;

                    for (int res_i = 0; res_i < res_print_num; res_i++) {
                        // Print start of result
                        cout << res_i+1 << '.';
                        int curr_i_digits = (int)floor(log10 (abs (res_i+1))) + 1;
                        int sp_num = res_print_digits - curr_i_digits;
                        for (int i = 0; i < sp_num; i++)
                            cout << ' ';

                        cout << '(';
                        int curr_id_digits = (int)floor(log10 (abs (results[res_i]->get_doc_id()))) + 1;
                        sp_num = max_id_digits - curr_id_digits;
                        for (int i = 0; i < sp_num; i++)
                            cout << ' ';

                        cout << results[res_i]->get_doc_id() << ")[";
                        if (results[res_i]->get_rel_score() >= 0 && neg_val == 1)
                            cout << ' ';
                        int curr_score_digits = (int)floor(log10 (abs ((int)results[res_i]->get_rel_score()))) + 1;
                        sp_num = max_score_digits -  curr_score_digits;
                        for (int i = 0; i < sp_num; i++)
                            cout << ' ';
                        cout << fixed << setprecision(4) << results[res_i]->get_rel_score() << "] ";

                        // Print text and underline found words
                        bool next_res = false;
                        int index = 0;
                        while(next_res == false) {
                            if (index != 0)
                                for (int i = 0; i < offset; i++)
                                    cout << ' ';

                            int new_l_off = 0;
                            int i = 0;
                            int curr_doc_id = results[res_i]->get_doc_id();
                            // Find where to change line
                            while (i < col_num - offset && next_res == false) {
                                if (map[curr_doc_id][index + i] == '\0') {
                                    next_res = true;
                                    new_l_off = i;
                                }
                                else if (isspace(map[curr_doc_id][index + i]))
                                    new_l_off = i;

                                i++;
                            }
                            // Print this line
                            for (i = 0; i < new_l_off; i++) {
                                if (isspace(map[curr_doc_id][index + i]))
                                    cout << ' ';
                                else
                                    cout << map[curr_doc_id][index + i];
                            }
                            cout << '\n';

                            // Next line (for underlining found words)
                            for (i = 0; i < offset; i++)
                                cout << ' ';
                            i = 0;
                            while (i < new_l_off) {
                                // Print spaces for spaces
                                if (isspace(map[curr_doc_id][index + i])) {
                                    cout << ' ';
                                    i++;
                                }
                                // Only print '^' for found words
                                else {
                                    int curr_len = word_len(&map[curr_doc_id][index + i]);
                                    // For words in query, check if its the same word
                                    int search_w_i = 0;
                                    bool match = false;
                                    while (search_w_i < input_num-1 && !match) {
                                        int in_len = word_len(comm_words[search_w_i]);
                                        if (curr_len == in_len
                                            && strncmp(comm_words[search_w_i], &map[curr_doc_id][index + i],
                                                       in_len) == 0) {
                                            match = true;
                                        }
                                        search_w_i++;
                                    }
                                    // If it is, print '^' equal to the length of the word, else print ' '
                                    while (!isspace(map[curr_doc_id][index + i])
                                           && map[curr_doc_id][index + i] != '\0') {
                                        if (match)
                                            cout << '^';
                                        else
                                            cout << ' ';
                                        i++;
                                    }
                                }
                            }
                            cout << '\n';
                            index = index + new_l_off + 1;
                        }
                    }
                    cout << endl;
                }

                // Else no results found
                else
                    cout << "No results found for query" << endl;

                // Free results
                for (int i = 0; i < result_num; i++)
                    delete results[i];
                free(results);
            }
            else if (strncmp(&line[index], "/exit", 5) == 0
                     && input_num == 1) {
                exit_prog = true;
            }
            // Wrong command, explain
            else {
                explain_commands();
            }

        }
    }

    /**
    * End program
    */

    // Free each saved document in the map
    for (int i = 0; i < N; i++)
        free(map[i]);
    // Free input document map
    free(map);
    // Free saved document word numbers
    free(map_word_num);
    // Free line buffer
    free(line);
    // Close input file
    fclose(docfile_ptr);

    return 0;
}