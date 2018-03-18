#include "query_result.h"

QueryResult::QueryResult(int id, double score) : doc_id(id), rel_score(score) { }


QueryResult::~QueryResult() { }


int QueryResult::get_doc_id() { return doc_id; }


double QueryResult::get_rel_score() { return rel_score; }
