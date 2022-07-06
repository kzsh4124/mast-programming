#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 100


/* define linked list(datatype: char*) */

struct Element {
    char* val;
    struct Element *prev;
    struct Element *next;
};

struct LIST {
    struct Element *h;
    struct Element *t;
};

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

void appendElement(struct LIST *l, char* s){
    struct Element *e;

    e=getElement(s);
    l->t->next = e;
    e->prev = l->t;
    l->t = e;
}



void printAllElements(struct LIST *l){
    struct Element *e;
    puts("{");
    for(e=l->h->next; e != NULL; e = e->next){
        printf("%s\n", e->val);
    }
    puts("}");
}

void free_list(struct LIST *l){
    struct Element *now, *next;
    now = l->h;
    while(1){
        free(now->val);
        next = now->next;
        free(now);
        now = next;
        if(now == NULL){
            break;
        }
    }
}

/* string control */

char* chomp(char* s){
    int l = strlen(s);
    if(l>0 && s[l-1]=='\n'){
        s[l-1] = '\0';
    }
}


/* convert csv formatted string into linked list */

struct LIST* csv2list(char* str){
    int i;
    char* token; 
    char* head = str;
    char delim = ',';
    struct LIST* line = initList();

    chomp(str);
    for(i=0; i<strlen(str)+1; i++){
        if(str[i]== delim || str[i]=='\0'){
            str[i] = '\0';
            token = (char*) malloc(strlen(head)+1);
            strcpy(token, head);
            appendElement(line, token);
            head = &str[i+1];
        }
    }
    return line;
}


int main(int ac, char* av[]){
    FILE *fp;
    char buf[BUFSIZE];
    struct LIST* line_list;

    if(ac != 2){
        puts("invalid args!");
        exit(EXIT_FAILURE);
    }

    fp = fopen(av[1], "r");
    if(fp==NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while(1){
        if(fgets(buf, BUFSIZE, fp) == NULL){
            if(ferror(fp) != 0){
                perror("fgets");
                exit(EXIT_FAILURE);
            }else{
                break;
            }
        }

        line_list = csv2list(buf);
        printAllElements(line_list);
        //free_list(line_list);
    }
    fclose(fp);
}
