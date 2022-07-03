#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 100

struct Element {
    char* val;
    struct Element *prev;
    struct Element *next;
};

struct LIST {
    struct Element *h;
    struct Element *t;
};
/* create new element (value: int n)*/
struct Element *getElement(char* s){
    struct Element *p;

    p = (struct Element*)malloc(sizeof(struct Element));
    if (p == NULL){
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    p->val = s;
    p->prev = NULL;
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

    l->h = getElement("");
    l->t = l->h;

    return l;
}

/* add new element */
void appendElement(struct LIST *l, char* s){
    struct Element *e;

    e=getElement(s);
    l->t->next = e;
    e->prev = l->t;
    l->t = e;
}



void printAllElements(struct LIST *l){
    struct Element *e;

    for(e=l->h->next; e != NULL; e = e->next){
        printf("%s\n", e->val);
    }
}

/* string control */

char* chomp(char* s){
    int l = strlen(s);
    if(l>0 && s[l-1]=='\n'){
        s[l-1] = '\0';
    }
}

char* get_line(void){
    char buf[BUFSIZE];
    if(fgets(buf, BUFSIZE, stdin) != NULL){
        chomp(buf);
        return buf;
    }else{
        return NULL;
    }
}

int main(int ac, char* av[]){
    struct LIST *list;
    int i;
    char* buf, line;

    list1 = initList();
    while(1){
        buf = get_line();
        if(buf == NULL){
            break;
        }
        line = (char*) malloc(strlen(buf)+1);
        if(line == NULL){
            puts("memory allocation failure!");
            exit(EXIT_FAILURE);
        }
        strcpy(line, buf);
        appendElement(list, line);
    }

    printAllElements(list);

}
