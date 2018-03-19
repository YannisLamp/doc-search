#ifndef SYSPRO_PROJECT_1_QUERYRESULT_H
#define SYSPRO_PROJECT_1_QUERYRESULT_H

/*
 * QueryResult class
 * Just makes it easier to store and sort
 * document ids and their relativity scores to a query
 * It has only getter methods
 */

class QueryResult {
private:
    int doc_id;
    double rel_score;

public:
    QueryResult(int id, double score);
    ~QueryResult();

    int get_doc_id();
    double get_rel_score();
};


#endif //SYSPRO_PROJECT_1_QUERYRESULT_H
