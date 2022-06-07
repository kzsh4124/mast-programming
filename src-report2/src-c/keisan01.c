#include<stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(){
  char s[SSIZE];

  return atoi(fgets(s, SSIZE, stdin));
}
int main(void){
    int a,b,c;
    
    printf("input an interger number(a): ");
    a = getint();
    printf("input an interger number(b): ");
    b = getint();
    printf("input an interger number(c): ");
    c = getint();
    printf("value (a) is %d\n",a);
    printf("value (b) is %d\n",b);
    printf("value (c) is %d\n",c);
}
