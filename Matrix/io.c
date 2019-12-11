#include<stdio.h>
#include<stdlib.h> 
#include "./matrix.h"
#include "./simplex.h"
#include "./io.h"





char* get_line(FILE *file){

	char* line = NULL;
	char c;
	int buff = 0;

	while(1){
		
		c = fgetc(file);
		// printf("%c",c);
		if(c == EOF || c == '\n')
			break;
		buff++;

		char* checker =  realloc(line, sizeof(char) * (buff + 1));

		if(checker == NULL)
			free(checker);
		else
		{
			line = checker;
		}
		
		line[buff - 1] = c;
	}
	if(line != NULL){
		line[buff] = '\0';
	}
	
	return line;
}


FILE_CONTENT read_lines(FILE *file){
	FILE_CONTENT fc;
    fc.content = NULL;
    fc.r = 0;

	char* line = NULL;
	line = get_line(file);

	while(line != NULL){
		// printf("%d\n",row_i);
		fc.r++;
		char** checker = realloc(fc.content, sizeof(char*) * (fc.r + 1));

		if(checker == NULL){
			free(checker);
			break;
		}
		else
		{
			fc.content = checker;
		}
		
		fc.content[fc.r - 1] = line;
		line = get_line(file);
	}

	// printf("done\n");
	fc.content[fc.r] = NULL;
	return fc;
}


void FC_free(FILE_CONTENT fc){
    for(int i = 0;i<fc.r; i++){
        free(fc.content[i]);
    }
    free(fc.content);
}


float* tokenize_line(char* line){
    float* fline = NULL;
    char* end;
    int i = 0;

    for (float f = strtof(line, &end); line != end; f = strtof(line, &end)){
        // printf(" -> %f\n", f);
        line = end;
        i++;
        fline = realloc(fline, sizeof(float) * i);
        fline[i - 1] = f;
    }

    return fline;
}


