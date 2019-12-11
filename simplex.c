#include<stdio.h>
#include<stdlib.h> 
#include "./Matrix/matrix.h"
#include "./Matrix/io.h"
#include "./simplex.h"



// FILE TO SIMPLEX WORKS AS FOLLOWS : 
    // -> 
    // ->

MATRIX* load_matrix(char** content, int rows, int cols, int startwith){

    MATRIX *m = Matrix(rows, cols, 0);
    
    for (int i = 0; i < rows; i++){
        float* fline = tokenize_line(content[startwith + i]);

        for (int j = 0; j < cols; j++){
            m->data[i][j] = fline[j];
        }
        
        free(fline);       
    }
    
    
    return m;
}


LINEAR_PROGRAM file_to_LP(char* file_path){
    LINEAR_PROGRAM lp;
    FILE* f = fopen(file_path, "r");
    FILE_CONTENT fc = read_lines(f);
    float* fline  = tokenize_line(fc.content[0]);
    int nbr_of_matrices = (int)fline[0];
    MATRIX** matrices = malloc(sizeof(MATRIX*) * nbr_of_matrices);
    free(fline);    

    int i = 0;
    int current_m = 1;

    while(i < nbr_of_matrices){
        fline  = tokenize_line(fc.content[current_m]);
        matrices[i] = load_matrix(fc.content, (int)fline[0], (int)fline[1], current_m + 1);
        current_m += fline[0] + 1;
        free(fline);
        i++;
    }

    lp.A = matrices[0];
    lp.B = NULL;
    lp.R = NULL;
    lp.c= matrices[1];
    lp.cb = NULL;
    lp.cr = NULL;
    lp.basis_indices = matrices[2];
    lp.b = matrices[3];
    
    // for (i = 0; i < nbr_of_matrices; i++){
    //     fmatrix(matrices[i]);
    //     free(matrices[i]);
    //     matrices[i] = NULL;
    // }

    free(matrices);
    
    
    FC_free(fc);
    fclose(f);

    return lp;
}


void refine_LP(LINEAR_PROGRAM *lp){
    lp->B = split_cols(*lp->A, *lp->basis_indices, 1);
    lp->R = split_cols(*lp->A, *lp->basis_indices, 0);
    lp->cb = split_cols(*lp->c, *lp->basis_indices, 1);
    lp->cr = split_cols(*lp->c, *lp->basis_indices, 0);
}


void __ptableau_header(LINEAR_PROGRAM lp, MATRIX not_base){
    printf("SIMPLEX TABLEAU : \n\n");
    printf("|% 8s|","BASE");
    for(int i = 0;i<lp.basis_indices->cols_len;i++){
        printf("% 7s%d|","X",(int)lp.basis_indices->data[0][i]+1);
    }
    
    for(int i = 0;i<not_base.cols_len;i++){
        printf("% 7s%d|","X",(int)not_base.data[0][i]+1);
    }

    printf("% 8s|","-Z");
    printf("% 8s|","TERMS");
    printf("\n");
}

void __ptableau_section(LINEAR_PROGRAM lp, MATRIX not_base, MATRIX BiR, MATRIX Bib){
    MATRIX* identity = identityOf(lp.basis_indices->cols_len);
    
    
    for(int i = 0;i<lp.basis_indices->cols_len;i++){
        printf("|% 7s%d|","X",(int)lp.basis_indices->data[0][i] + 1);
        
        for (int j = 0 ; j<lp.basis_indices->cols_len; j++){
            printf("%8.1f|", identity->data[i][j]);
        }

        for (int j = 0 ; j<BiR.cols_len; j++){
            printf("%8.1f|", BiR.data[i][j]);
        }

        printf("%8.1f|", 0.0);
        printf("%8.1f|", Bib.data[i][0]);        

        printf("\n");
    }

    
    fmatrix(identity);
}

void __ptableau_footer(LINEAR_PROGRAM lp, MATRIX not_base, MATRIX j, MATRIX ib){
    printf("|% 8s|","-Z");

    for (int i = 0 ; i<lp.basis_indices->cols_len; i++){
        printf("%8.1f|", 0.0);
    }

    for(int i = 0;i<not_base.cols_len;i++){
        printf("%8.1f|", j.data[0][i]);
    }

    printf("%8.1f|", 1.0);
    printf("%8.1f|", ib.data[0][0]);

}

void ptableau(LINEAR_PROGRAM lp){
    MATRIX* not_base = not_in_sequence(*lp.basis_indices, lp.A->cols_len);
    MATRIX* Bi = inv(*lp.B);
    MATRIX* BiR = dot(*Bi, *lp.R);
    MATRIX* bt = T(*lp.b);
    MATRIX* Bib = dot(*Bi, *bt);
    MATRIX* i = dot(*lp.cb, *Bi);
    MATRIX* iR = dot(*i, *lp.R);
    MATRIX* j = sub(*lp.cr, *iR);
    MATRIX* ib = dot(*i, *bt);
    ib->data[0][0] *= -1;

    printf("\n");
    __ptableau_header(lp,*not_base);
    __ptableau_section(lp,*not_base, *BiR, *Bib);
    __ptableau_footer(lp,*not_base, *j, *ib);
    printf("\n\n");

    fmatrix(j);
    fmatrix(i);
    fmatrix(iR);
    fmatrix(ib);
    fmatrix(not_base);
    fmatrix(bt);
    fmatrix(Bi);
    fmatrix(BiR);
    fmatrix(Bib);
}

void fLP(LINEAR_PROGRAM *s){
    fmatrix(s->A);
    fmatrix(s->B);
    fmatrix(s->R);
    fmatrix(s->c);
    fmatrix(s->cb);
    fmatrix(s->cr);
    fmatrix(s->b);
    fmatrix(s->basis_indices);
}