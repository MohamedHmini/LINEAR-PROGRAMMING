#include<stdio.h>
#include<stdlib.h> 


#ifndef IO_H
#define IO_h


typedef struct FILE_CONTENT{
    char** content;
    int r;
}FILE_CONTENT;



char* get_line(FILE*);
FILE_CONTENT read_lines(FILE*);
void FC_free(FILE_CONTENT);
float* tokenize_line(char*);


#endif



