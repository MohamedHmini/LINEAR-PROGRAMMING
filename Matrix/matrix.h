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


typedef struct CMP_RESULT{
    float val;
    int index;
}CMP_RESULT;


MATRIX* Matrix(int,int,float);
MATRIX* identityOf(int); //  of rank
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
MATRIX* divide(MATRIX, MATRIX);
MATRIX* inv(MATRIX);
MATRIX* merge_cols(MATRIX, MATRIX);
MATRIX* merge_rows(MATRIX, MATRIX);
MATRIX* split_cols(MATRIX, MATRIX, int); // the int takes two values (0) for not in, (1) for in;
MATRIX* split_rows(MATRIX, MATRIX, int); // the int takes two values (0) for not in, (1) for in;
MATRIX* remove_col(MATRIX, int);
MATRIX* get_col(MATRIX, int);
void switch_cols(MATRIX*, MATRIX*, int, int);
float det(MATRIX);
CMP_RESULT min(MATRIX);
CMP_RESULT max(MATRIX);
float sum(MATRIX);
float product(MATRIX);



#endif