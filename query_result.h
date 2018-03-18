#ifndef SYSPRO_PROJECT_1_QUERYRESULT_H
#define SYSPRO_PROJECT_1_QUERYRESULT_H


class QueryResult {
private:
    int doc_id;
    double rel_score;

public:
    int get_doc_id();
    double get_rel_score();
};


#endif //SYSPRO_PROJECT_1_QUERYRESULT_H
