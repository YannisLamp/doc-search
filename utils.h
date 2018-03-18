#ifndef UTILS
#define UTILS

// Uti
void explain_args(char* pname);
void explain_commands();
int get_word_num(char* doc);
int get_next_word_index(char* doc, int index);
void alloc_chk(void* alloc_ptr);
void print_until_space(char* word);
int word_len(char* word);











#endif