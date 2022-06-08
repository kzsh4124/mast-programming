#include<stdio.h>
#include <stdlib.h>

#define SSIZE 100

int getint(void){
  char s[SSIZE];
  return atoi(fgets(s, SSIZE, stdin));
}
int mygetint(char var_name[]){
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
int randint(int a, int b){
  if(a == b){
    return a;
  }else{
    return a-1 + myrand(b-a+1);
  }
}
void play_A(void){
    int a, b, c;
    int n;
    do{
        n = randint(6,90);
    }while(n == 82);
    printf("a * b + c = %d\n",n);
    while(1){
      a = mygetint("a");
      b = mygetint("b");
      c = mygetint("c");
      
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
      a = mygetint("a");
      b = mygetint("b");
      c = mygetint("c");
      
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
    srand(time(NULL));
    int rep;
    int i=0;
    if(argc != 2){
        printf("Invalid argment(s)!\n");
        return 1;
    }
    rep = atoi(argv[1]);
    if(rep == 0){
        printf("Invalid argment(s)!\n");
        return 1;
    }
    for(i=0; i< rep; i++){
        rand_expression = randint(0,1);
        if(rand_expression == 0){
            play_A();
        }else{
            play_B();
        }
    }
}
