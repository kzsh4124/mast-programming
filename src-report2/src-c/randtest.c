#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand(int n){
  return rand()%n +1;
}

int main(int ac, char *av[]){
  int i;

  srand(time(NULL));

  printf("%d\n", RAND_MAX);

  for(i=0; i<100; i++){
    printf("%4d", myrand(100));
  }
}
