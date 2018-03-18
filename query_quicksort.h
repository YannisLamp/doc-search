#ifndef SYSPRO_PROJECT_1_QUICKSORT_H
#define SYSPRO_PROJECT_1_QUICKSORT_H

#include "query_result.h"

void query_quicksort(QueryResult** results, int low, int high);
int query_partition(QueryResult** results, int low, int high);
void result_swap(QueryResult* left, QueryResult* right);

#endif
