#include<stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(){
  char s[SSIZE];

  return atoi(fgets(s, SSIZE, stdin));
}
int main(void){
    int a,b,c;
    // aの入力
    while (1){
      printf("input an interger number(a): ");
      a = getint();
      if(1<=a && a<=9){
        break;
      }else{
        printf("Invalid value. Retype an integer in range 2-9.\n");
      }
    }
    //bの入力
    while(1){
      printf("input an interger number(b): ");
      b = getint();
      if(1<=b && b<=9){
        break;
      }else{
        printf("Invalid value. Retype an integer in range 2-9.\n");
      }
    }
    //cの入力
    while(1){
      printf("input an interger number(c): ");
      c = getint();
      if(1<=c && c<=9){
        break;
      }else{
        printf("Invalid value. Retype an integer in range 2-9.\n");
      }
    }
    printf("value (a) is %d\n",a);
    printf("value (b) is %d\n",b);
    printf("value (c) is %d\n",c);
}
