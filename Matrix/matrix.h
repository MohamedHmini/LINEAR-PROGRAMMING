


#ifndef MATRIX_H
#define MATRIX_H


typedef struct MATRIX{
    float** data;
    // shape : 
    int rows_len;
    int cols_len;
}MATRIX;



MATRIX* Matrix(int,int,float);
void fmatrix(MATRIX*);
void pmatrix(MATRIX);

// matrix operations : 
MATRIX* T(MATRIX);
MATRIX* dot(MATRIX, MATRIX);
MATRIX* add(MATRIX, MATRIX);
MATRIX* sub(MATRIX, MATRIX);
MATRIX* inv(MATRIX);
MATRIX* merge_cols(MATRIX, MATRIX);
MATRIX* merge_rows(MATRIX, MATRIX);
float det(MATRIX);



#endif