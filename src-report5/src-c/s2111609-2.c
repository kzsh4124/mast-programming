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

    l->h = getElement(NULL);
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
        /* free string */
        if(now->val != NULL){
            free(now->val);
        }
        /* free Element */
        next = now->next;
        free(now);
        now = next;
        if(now == NULL){
            break;
        }
    }
    /* free list */
    free(l);
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
    int len_str;
    char delim = ',';
    struct LIST* line = initList();
    chomp(str);
    len_str = strlen(str)+1;

    for(i=0; i<len_str; i++){
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

/* HTML control */
void print_html_head(FILE* fp, char* title){
    fprintf(fp, "<!DOCTYPE html>\n");
    fprintf(fp, "<html>\n");
    fprintf(fp,"<head>\n");
    fprintf(fp, "<title>%s</title>\n", title);
    fprintf(fp, "</head>\n");
}
void print_html_body_table(FILE* fp, char* heading){
    fprintf(fp, "<body>\n");
    fprintf(fp, "<h1>%s</h1>\n", heading);
    fprintf(fp, "<table border=\"1\">\n");
}
void print_table_record(FILE* fp, struct LIST* l){
    struct Element* e;
    fprintf(fp, "<tr> ");
    for(e=l->h->next; e != NULL; e = e->next){
        fprintf(fp, "<td>%s</td> ", e->val);
    }
    fprintf(fp, "</tr>\n");
}
void print_html_close(FILE* fp){
    fprintf(fp, "</table>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");
}

int main(int ac, char* av[]){
    FILE *fp_csv, *fp_html;
    char buf[BUFSIZE];
    struct LIST* line_list;

    /* you need input & output file name */
    if(ac != 3){
        puts("invalid args!");
        exit(EXIT_FAILURE);
    }
    /* open csv */
    fp_csv = fopen(av[1], "r");
    if(fp_csv==NULL){
        perror("fopen_csv");
        exit(EXIT_FAILURE);
    }
    /* open html as write mode */
    fp_html = fopen(av[2], "w");
    if(fp_html == NULL){
        perror("fopen_html");
        exit(EXIT_FAILURE);
    }

    /* write html head */
    print_html_head(fp_html, "csv2table");

    /* write html body/table(start) */
    print_html_body_table(fp_html, "csv2table");

    /* convert csv to html table */
    while(1){
        if(fgets(buf, BUFSIZE, fp_csv) == NULL){
            if(ferror(fp_csv) != 0){
                perror("fgets");
                exit(EXIT_FAILURE);
            }else{
                break;
            }
        }
        line_list = csv2list(buf);
        printAllElements(line_list);
        print_table_record(fp_html, line_list);
        free_list(line_list);
    }
    /*close html tags*/
    print_html_close(fp_html);
    /*close file stream*/
    fclose(fp_csv);
    fclose(fp_html);
}
