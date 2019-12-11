#include "./Matrix/matrix.h"


#ifndef SIMPLEX_H
#define SIMPLEX_H


typedef struct LINEAR_PROGRAM{
    MATRIX* A;
    MATRIX* B;
    MATRIX* R;
    MATRIX* b;
    MATRIX* c;
}LINEAR_PROGRAM;



LINEAR_PROGRAM file_to_LP(char*);
MATRIX* load_matrix(char**, int, int, int);
void fLP(LINEAR_PROGRAM*);

#endif