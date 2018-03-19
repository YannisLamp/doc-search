#ifndef SYSPRO_PROJECT_1_QUICKSORT_H
#define SYSPRO_PROJECT_1_QUICKSORT_H

#include "query_result.h"

/*
 * Standard quicksort algorthm implemented for sorting records
 * of a result query array
 *
 * Results is the query result array, low and high are the starting
 * and ending indexes respectively
 *
 * In this implementation the last element is always picked as pivot
 */

void query_quicksort(QueryResult** results, int low, int high);
int query_partition(QueryResult** results, int low, int high);
void result_swap(QueryResult* left, QueryResult* right);

#endif
