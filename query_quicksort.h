#ifndef SYSPRO_PROJECT_1_QUICKSORT_H
#define SYSPRO_PROJECT_1_QUICKSORT_H

#include "query_result.h"

void quicksort(QueryResult** results, int low, int high);
int partition(QueryResult** results, int low, int high);
void result_swap(QueryResult** left, QueryResult** right);

#endif
