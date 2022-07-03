#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BSIZE 100
#define LSIZE 10000

int main(void){
    char **buff;
    char **file;
    int i;
    int line_counter = 0;

    /* Make a 2-dimension dinamic array */
    buff= (char**) malloc(sizeof(char*)*LSIZE);
    if(buff == NULL){
        puts("memory allocation failure");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<LSIZE; i++){
        buff[i]= (char*) malloc(BSIZE);
        if(buff[i] == NULL){
            puts("memory allocation failure");
            exit(EXIT_FAILURE);
        }
    }
    /*Get lines*/
    i=0;
    while(fgets(buff[i],BSIZE,stdin) != NULL){
        i++;
        line_counter++;
    }
    /*Make a perfectly fited 2-dimension dinamic array */
    file = (char**) malloc(sizeof(char*)*line_counter);
    if(file == NULL){
        puts("memory allocation failure");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<line_counter; i++){
        file[i]= (char*) malloc(strlen(buff[i])+1 );
        if(file[i] == NULL){
            puts("memory allocation failure");
            exit(EXIT_FAILURE);
        }
        strcpy(file[i], buff[i]);
    }
    /*output*/
    for(i=0; i<line_counter; i++){
        printf("%5d %s", i+1, file[i]);
    }
    
    /*free*/
    for(i=0; i<LSIZE; i++){
        free(buff[i]);
    }
    for(i=0; i<line_counter; i++){
        free(file[i]);
    }
    free(buff);
    free(file);
}
