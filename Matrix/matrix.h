/////////////////////////////
/// MOHAMED-HMINI //////////////////////////
//////// 2019-2020 //////////


#ifndef MATRIX_H
#define MATRIX_H


typedef struct MATRIX{
    float** data;
    // shape : 
    int rows_len;
    int cols_len;
}MATRIX;



MATRIX* Matrix(int,int,float);
MATRIX* identityOf(int);
MATRIX* sequence(int,int); // args : from, to 
int in(MATRIX, float);
MATRIX* not_in_sequence(MATRIX, int);
MATRIX* copy(MATRIX);
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
MATRIX* split_cols(MATRIX, MATRIX, int); // the int takes two values (0) for not in, (1) for in;
MATRIX* split_rows(MATRIX, MATRIX, int); // the int takes two values (0) for not in, (1) for in;
float det(MATRIX);



#endif