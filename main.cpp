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

    FILE* docfile_ptr = fopen(docfile, "r");
    if (docfile_ptr == NULL) {
        cerr << "File " << docfile << " could not be opened" << endl;
        return 1; 
    }
    int curr_id = 0;
    char* line = nullptr;
    size_t len = 0;
    ssize_t read = 0;

    // Get first line
    read = getline(&line, &len, docfile_ptr);
    if (read == -1) {
        cerr << "Input file is empty" << endl;
        return 1;
    }


    // For each line of the input file
    // https://linux.die.net/man/3/getline
    while ((read = getline(&line, &len, docfile_ptr)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);



    }




    // Free line buffer
    free(line);




    
}
