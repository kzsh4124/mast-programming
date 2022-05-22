#include <stdio.h>

void sort(int n, int num[]){
  int i, j;

  for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if (num[i] > num[j]){
        int tmp;
        tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
      }
    }
  }
}

int main(int ac, char* av[]){
  int num[] = { 3, 1, 4, 5, 9, 2, 6, 8, 7 };
  int i;

  for(i = 0; i < 9; i++){
    printf("%3d", num[i]);
  }
  printf("\n");

  sort(9, num);

  for(i = 0; i < 9; i++){
    printf("%3d", num[i]);
  }
  printf("\n");
}
