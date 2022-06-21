#include<stdio.h>
#include<string.h>

#define BSIZE 100
#define LSIZE 10000

int main(void){
    char s[LSIZE][BSIZE];
    char file[LSIZE][BSIZE];
    int i;
    int line_counter = 0;

    while(fgets(s[i],BSIZE,stdin) != NULL){
        i++;
        line_counter++;
    }

    for(i=0; i<line_counter; i++){
        strcpy(file[i], s[i]);
    }
    for(i=0; i<line_counter; i++){
        printf("%5d %s", i+1, file[i]);

    }
}
