#include<stdbool.h>
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
    MATRIX* not_basis_indices;
    bool optimal;
}LINEAR_PROGRAM;



LINEAR_PROGRAM file_to_LP(char*);
MATRIX* load_matrix(char**, int, int, int);
void refine_LP(LINEAR_PROGRAM*, int);
int current_simplex(LINEAR_PROGRAM*);
int next_simplex(LINEAR_PROGRAM*, MATRIX, MATRIX, MATRIX);
void run_simplex(LINEAR_PROGRAM*);
void fLP(LINEAR_PROGRAM*);

#endif