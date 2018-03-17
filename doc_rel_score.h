#ifndef SYSPRO_PROJECT_1_DOCRELSCORE_H
#define SYSPRO_PROJECT_1_DOCRELSCORE_H


class DocRelScore {
private:
    int doc_id;
    double rel_score;

public:
    // Oveload < operator
    bool operator < (DocRelScore const &left, DocRelScore const &right);
};


#endif //SYSPRO_PROJECT_1_DOCRELSCORE_H
