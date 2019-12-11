#include<stdio.h>
#include<stdlib.h>
#include "./matrix.h"










MATRIX *Matrix(int rows, int cols, float init_val){
    MATRIX *m = malloc(sizeof(MATRIX));
    m->rows_len = rows;
    m->cols_len = cols;
    m->data = malloc(sizeof(float**) * rows);
    
    for (int i = 0; i < rows; i++){
        m->data[i] = malloc(sizeof(float*) * cols);
        for (int j = 0; j < cols; j++){
            m->data[i][j] = init_val;
        }        
    }

    return m;
}


void fmatrix(MATRIX *m){
    for (int i = 0; i < m->rows_len; i++){
        free(m->data[i]); 
    }
    free(m->data);
    free(m);
}


void pmatrix(MATRIX m){
    printf("ROWS : %d\n", m.rows_len);
	printf("COLS : %d\n", m.cols_len);

    for (int i = 0; i < m.rows_len; i++){
        printf("[ ");
        for (int j = 0; j < m.cols_len; j++){
            printf("%05.2f ",m.data[i][j]);
        }  
        printf("]\n");      
    }
}




MATRIX* T(MATRIX m){
    MATRIX* tm = Matrix(m.cols_len, m.rows_len, 0);

    for (int i = 0; i < tm->rows_len; i++){
        for (int j = 0; j < tm->cols_len; j++){
            tm->data[i][j] = m.data[j][i];
        }        
    }
    
    return tm;
}


MATRIX* add(MATRIX A, MATRIX B){
    if(A.cols_len != B.cols_len || A.rows_len != B.rows_len)
        return NULL;

    MATRIX *m = Matrix(A.rows_len, A.cols_len, 0);

    for (int i = 0; i < m->rows_len; i++){
        for (int j = 0; j < m->cols_len; j++){
            m->data[i][j] = A.data[i][j] + B.data[i][j];
        }        
    } 

    return m;   
}


MATRIX* sub(MATRIX A, MATRIX B){
    if(A.cols_len != B.cols_len || A.rows_len != B.rows_len)
        return NULL;

    MATRIX *m = Matrix(A.rows_len, A.cols_len, 0);

    for (int i = 0; i < m->rows_len; i++){
        for (int j = 0; j < m->cols_len; j++){
            m->data[i][j] = A.data[i][j] - B.data[i][j];
        }        
    } 

    return m;   
}



MATRIX* merge_cols(MATRIX A, MATRIX B){
    if(A.rows_len != B.rows_len)
        return NULL;

    MATRIX *m = Matrix(A.rows_len, A.cols_len + B.cols_len, 0);

    for (int i = 0; i < A.rows_len; i++){
        for (int j = 0; j < A.cols_len; j++){
            m->data[i][j] = A.data[i][j];
        }        
    }

    for (int i = 0; i < A.rows_len; i++){
        for (int j = A.cols_len; j < A.cols_len + B.cols_len; j++){
            m->data[i][j] = B.data[i][j - A.cols_len];
        }        
    }

    return m;
}



MATRIX* merge_rows(MATRIX A, MATRIX B){
    if(A.cols_len != B.cols_len)
        return NULL;

    MATRIX *m = Matrix(A.rows_len + B.rows_len, A.cols_len, 0);

    for (int i = 0; i < A.rows_len; i++){
        for (int j = 0; j < A.cols_len; j++){
            m->data[i][j] = A.data[i][j];
        }        
    }

    for (int i = A.rows_len; i < A.rows_len + B.rows_len; i++){
        for (int j = 0; j < B.cols_len; j++){
            m->data[i][j] = B.data[i - A.rows_len][j];
        }        
    }

    return m;
}



MATRIX* dot(MATRIX A, MATRIX B){
    if(A.cols_len != B.rows_len)
        return NULL;

    MATRIX* m = Matrix(A.rows_len, B.cols_len, 0);

    for (int i = 0; i < m->rows_len; i++){
        for (int j = 0; j < m->cols_len; j++){
            float v = 0;
            for (int k = 0; k < A.cols_len; k++){
                v += A.data[i][k]*B.data[k][j];
            }
            m->data[i][j] = v;            
        }  
    }    

    return m;
}



float det(MATRIX m){
    float d = 0;
    // magic ...
    return d;
}


MATRIX* inv(MATRIX A){
    MATRIX* Ai = Matrix(A.rows_len, A.cols_len, 0);
    // magic ...
    return Ai;
}