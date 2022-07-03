#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

struct Element {
int val;
struct Element *next;
};

struct LIST {
struct Element *h;
struct Element *t;
};

struct Element *getElement(int n){
struct Element *p;

p = (struct Element*)malloc(sizeof(struct Element));
if (p == NULL){
printf("Memory allocation error\n");
exit(EXIT_FAILURE);
}

p->val = n;
p->next = NULL;
return p;
}

struct LIST *initList(){
struct LIST *l;

l = (struct LIST*)malloc(sizeof(struct LIST));
if (l == NULL){
printf("Memory Allocation Error\n");
exit(EXIT_FAILURE);
}

l->h = getElement(0);
l->t = l->h;

return l;
}

void appendElement(struct LIST *l, int n){
struct Element *e;

e=getElement(n);
l->t->next = e;
l->t = e;
}

void printAllElements(struct LIST *l){
struct Element *e;

for(e=l->h->next; e != NULL; e = e->next){
printf("val = %d\n", e->val);
}
}

int getint(){
char buf[BUFSIZE];

fgets(buf, BUFSIZE, stdin);
return atoi(buf);
}

int main(int ac, char* av[]){
struct LIST *l1, *l2;
int i;

l1 = initList();
while(1){
printf("input a number (quit when 0): ");
i = getint();
if (i == 0){
break;
}
appendElement(l1, i);
}

printf("l1\n");
printAllElements(l1);

l2 = initList();
while(1){
printf("input a number (quit when 0): ");
i = getint();
if (i == 0){
break;
}
appendElement(l2, i);
}

printf("l2\n");
printAllElements(l2);
}
