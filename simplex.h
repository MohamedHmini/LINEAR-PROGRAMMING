#include "./Matrix/matrix.h"


#ifndef SIMPLEX_H
#define SIMPLEX_H


typedef struct LINEAR_PROGRAM{
    MATRIX* A;
    MATRIX* B;
    MATRIX* R;
    MATRIX* b;
    MATRIX* c;
    MATRIX* cb;
    MATRIX* cr;
    MATRIX* basis_indices;
}LINEAR_PROGRAM;



LINEAR_PROGRAM file_to_LP(char*);
void refine_LP(LINEAR_PROGRAM*);
MATRIX* load_matrix(char**, int, int, int);
void fLP(LINEAR_PROGRAM*);

#endif