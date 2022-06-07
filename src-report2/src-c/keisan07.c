#include<stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(void){
  char s[SSIZE];
  return atoi(fgets(s, SSIZE, stdin));
}
/* 2-9の整数を受け取るまで繰り返し入力を要求する関数 */
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
int myrand(int n){
  return rand()%n +1;
}
/* a以上b以下の整数を返す関数randint(pythonのrandom.randint()と類似する関数) */
int randint(int a, int b){
  srand(time(NULL));
  if(a == b){
    return a;
  }else{
    /* myrand(n)は1以上n以下の整数を返す */
    return a-1 + myrand(b-a+1);
  }
}
void play_A(void){
    int a, b, c;
    int n;
    do{
        n = randint(6,90);
    }while(n == 82);
    n = randint(6,90);
    printf("a * b + c = %d\n",n);
    while(1){
      /* aの入力 */
      a = input_valid_int("a");
      /* bの入力 */
      b = input_valid_int("b");
      /* cの入力 */
      c = input_valid_int("c");
      
      if(a * b + c == n){
        printf("good!\n");
        break;
      }else{
        printf("bad!\n");
      }
    }
}
void play_B(void){
    int a, b, c;
    int n;
    do{
        n = randint(0, 79);
    }while(n == 71);
    printf("a * b - c = %d\n",n);
    while(1){
      /* aの入力 */
      a = input_valid_int("a");
      /* bの入力 */
      b = input_valid_int("b");
      /* cの入力 */
      c = input_valid_int("c");
      
      if(a * b - c == n){
        printf("good!\n");
        break;
      }else{
        printf("bad!\n");
      }
    }
}
int main(int argc, char** argv){
    int rand_expression;
    int rep;
    int i=0;
    if(argc != 2){
        printf("Invalid argment(s)!\n");
        return 1;
    }
    rep = atoi(argv[1]);
    for(i=0; i< rep; i++){
        rand_expression = randint(0,1);
        if(rand_expression == 0){
            play_A();
        }else{
            play_B();
        }
    }
}
