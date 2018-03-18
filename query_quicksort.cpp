#include <iostream>

#include "query_quicksort.h"
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

void query_quicksort(QueryResult** results, int low, int high) {
    if (low < high) {
        int pivot_location = query_partition(results, low, high);
        // Call recursively for before and after pivot location
        query_quicksort(results, low, pivot_location - 1);
        query_quicksort(results, pivot_location + 1, high);
    }
}

int query_partition(QueryResult** results, int low, int high) {
    QueryResult* pivot = results[high];
    int leftwall = low - 1;

    for (int i = low; i <= high - 1; i++) {
        if (results[i]->get_rel_score() > pivot->get_rel_score()) {
            leftwall++;
            result_swap(results[i], results[leftwall]);
        }
    }
    leftwall++;
    result_swap(pivot, results[leftwall]);
    return leftwall;
}

void result_swap(QueryResult* left, QueryResult* right) {
    QueryResult temp = *left;
    *left = *right;
    *right = temp;
}