#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

struct Element {
    int val;
    struct Element *prev;
    struct Element *next;
};

struct LIST {
    struct Element *h;
    struct Element *t;
};
/* create new element (value: int n)*/
struct Element *getElement(int n){
    struct Element *p;

    p = (struct Element*)malloc(sizeof(struct Element));
    if (p == NULL){
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    p->val = n;
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

    l->h = getElement(0);
    l->t = l->h;

    return l;
}

/* add new element */
void appendElement(struct LIST *l, int n){
    struct Element *e;

    e=getElement(n);
    l->t->next = e;
    e->prev = l->t;
    l->t = e;
}

/* insert node v after node p */
void insert(struct LIST *l, struct Element *v, struct Element *p){
    /* when p->next is NULL, NULL->prev causes Segmentation Error! */
    if(p->next != NULL){
        p->next->prev = v;
    }
    v->next = p->next;
    p->next = v;
    v->prev = p;
    /* update tail element */
    if(l->t == p){
        l->t = v;
    }
}

void insertElement(struct LIST *l, int n){
    struct Element *e;
    struct Element *seek;
    seek = l->h;
    e = getElement(n);
    while(1){
        /* when seek is the tail element */
        if(seek->next == NULL){
            insert(l, e, seek);
            break;
        /* when you detect the correct place to insert */
        }else if(seek->next->val > n){
            insert(l, e, seek);
            break;
        }else{
            seek = seek->next;
        }
    }
}

void printAllElements(struct LIST *l){
    struct Element *e;

    for(e=l->h->next; e != NULL; e = e->next){
        printf("val = %d\n", e->val);
    }
}

void rprintAllElements(struct LIST *l){
    struct Element *e;
    for(e=l->t; e != l->h; e = e->prev){
        printf("val = %d\n", e->val);
    }
}

int getint(){
    char buf[BUFSIZE];
    fgets(buf, BUFSIZE, stdin);
    return atoi(buf);
}

int main(int ac, char* av[]){
    struct LIST *list1, *list2;
    int i;

    list1 = initList();
    list2 = initList();
    while(1){
        printf("input a number (quit when 0): ");
        i = getint();
        if (i == 0){
            break;
        }
        appendElement(list1, i);
        insertElement(list2, i);
    }

    printAllElements(list1);
    puts("sorted");
    printAllElements(list2);


}
