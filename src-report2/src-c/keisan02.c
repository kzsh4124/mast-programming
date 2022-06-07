#include<stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(){
  char s[SSIZE];

  return atoi(fgets(s, SSIZE, stdin));
}
int input_valid_int(char var_name[]){
  int num;
  while(1){
    printf("input an interger number(%s): ",var_name);
    num = getint();
    if(2 <= num && num <= 9){
      return num;
    }else{
      printf("Invalid value. Retype an integer in range 2-9.\n");
    }
  }
}
int main(void){
    int a,b,c;
    /* aの入力 */
    a = input_valid_int("a");
    /* bの入力 */
    b = input_valid_int("b");
    /* cの入力 */
    c = input_valid_int("c");
    printf("value (a) is %d\n",a);
    printf("value (b) is %d\n",b);
    printf("value (c) is %d\n",c);
}
