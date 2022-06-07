#include <stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(){
  char s[SSIZE];

  return atoi(fgets(s, SSIZE, stdin));
}

int main(int ac, char* av[]){
  int i;
  
  printf("input an integer: ");
  i = getint();
  printf("the square of the input is %d\n", i*i);
}
