#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev, *next;
    int data;
}node;

typedef struct list{
    node *front, *rear;
}list;

void init_ASCII(list *l){
    l->front = NULL;
    l->rear = NULL;
}

int isEmpty(list l){
    if(!l.front){
        return 1;
    }else return 0;
}

void insert(list *l, char d){
    node *nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data = d;
        nn->next = nn->prev = NULL;
    }
    if(isEmpty(*l)){
        l->front = nn;
        l->rear = nn;
    }else{
        l->rear->next = nn;
        nn->prev = l->rear;
        l->rear = nn;
    }
}

void ASCII_of(list *l, char c){ 
    int value = c;
    while(value!= 0){
        int z = value%10;
        // printf("%d ", z);
        insert(l, z);
        value = value/10;
    }
    return;
}

void traverse(list l){
    node *p = l.rear;
    if(!p){
        return;
    }
    printf("{ ");
    while(p){
        printf("%d ",p->data);
        p = p->prev;
    }
    printf("}");
    printf("\n");
}

void destroy(list *l){
    node *p = l->front;
    node *q = l->front;
    if(!p){
        return;
    }
    while(p){
        p = p->next;
        free(q);
        q = p;
        // printf("list destroyed. \n");
    }
    return;
}

int main() {

    list l1;

    init_ASCII(&l1);

    char c;
    printf("Enter your character: ");
    scanf("%c", &c);
    ASCII_of(&l1, c);

    traverse(l1);
    destroy(&l1);

return 0;

}