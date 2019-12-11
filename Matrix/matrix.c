/////////////////////////////
/// MOHAMED-HMINI //////////////////////////
//////// 2019-2020 //////////

#include<stdio.h>
#include<stdlib.h>
#include "./matrix.h"
#define TRUE 1
#define FALSE 0








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


MATRIX* identityOf(int rank){
    MATRIX *identity = Matrix(rank, rank, 0);

    for (int i = 0; i < rank; i++){
        for (int j = 0; j < rank; j++){
            if(i == j)
                identity->data[i][j] = 1;
        }        
    }

    return identity;
}

// not needed apparently :'( very sad 
// i did use it for a test :D very happy 
MATRIX* sequence(int from, int to){
    MATRIX* seq = Matrix(1, to - from , 0);

    for (int j = 0; j < seq->cols_len; j++){
            seq->data[0][j] = from + j;
    }

    return seq;
}


int in(MATRIX seq, float v){
    int is_in = FALSE;

    for (int j = 0; j < seq.cols_len; j++){
        if(seq.data[0][j] == v){
            is_in = TRUE;
            break;
        }            
    }  

    return is_in;
}

// damn it -_-
// works perfectly
MATRIX* not_in_sequence(MATRIX seq, int bound){
    MATRIX* new_seq = Matrix(1, bound - seq.cols_len, 0);
    int counter = 0;

    for (int j = 0; j < bound; j++){
        if(!in(seq, j)){
            new_seq->data[0][counter] = j;
            counter++;
        }
    }

    return new_seq;
}

MATRIX* copy(MATRIX m){
    MATRIX* c  = Matrix(m.rows_len, m.cols_len, 0);

    for (int i = 0; i < m.rows_len; i++){
        for (int j = 0; j < m.cols_len; j++){
            c->data[i][j] = m.data[i][j];
        }        
    }

    return c;
}

void fmatrix(MATRIX *m){
    if(m != NULL){
        for (int i = 0; i < m->rows_len; i++){
            free(m->data[i]); 
        }
        free(m->data);
        free(m);
        m = NULL;
    }
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
    int rank = A.rows_len;
    MATRIX* Ac = copy(A);
    MATRIX* Ai = identityOf(rank);
    
    for (int i = 0; i < rank; i++){
        ////// pivoting : //////////////// 
        MATRIX* p = identityOf(rank);
        p->data[i][i] = 1/Ac->data[i][i];

        MATRIX* Acc = copy(*Ac);
        fmatrix(Ac);
        Ac = dot(*p, *Acc);
        fmatrix(Acc);

        MATRIX* c = copy(*Ai);
        fmatrix(Ai);
        Ai = dot(*p, *c);

        fmatrix(c);
        fmatrix(p);  
        ///////////////////////////////

        ////// elimination : /////////////

        for (int j = 0; j < rank; j++){
            if(i != j){
                MATRIX* e = identityOf(rank);
                e->data[j][i] = -Ac->data[j][i];
                MATRIX* Acc = copy(*Ac);
                fmatrix(Ac);
                Ac = dot(*e, *Acc);
                fmatrix(Acc);
                // pmatrix(*e);
                MATRIX* c = copy(*Ai);
                fmatrix(Ai);
                Ai = dot(*e, *c);

                fmatrix(c);
                fmatrix(e);
            }
        }
        
        /////////////////////////////////

    }

    fmatrix(Ac);
    return Ai;
}


MATRIX* __split_cols_which_belong_to(MATRIX container, MATRIX indices){
    MATRIX* splited = Matrix(container.rows_len, indices.cols_len, 0);

    for (int i = 0; i < container.rows_len; i++){
        for (int j = 0; j < indices.cols_len; j++){
            int k = (int)indices.data[0][j];
            splited->data[i][j] = container.data[i][k];
        }        
    }

    return splited;
}

MATRIX* __split_cols_which_do_not_belong_to(MATRIX container, MATRIX indices){
    MATRIX* splited = NULL;
    MATRIX* new_indices = not_in_sequence(indices, container.cols_len);

    splited = __split_cols_which_belong_to(container, *new_indices);


    fmatrix(new_indices);
    return splited;
}


MATRIX* split_cols(MATRIX container, MATRIX indices, int belongs){
    MATRIX* splited = NULL;
    
    if(belongs == 1)
        splited = __split_cols_which_belong_to(container, indices);
    else
        splited = __split_cols_which_do_not_belong_to(container, indices);

    return splited;
}