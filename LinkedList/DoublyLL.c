#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    first = (Node *)malloc(sizeof(Node));
    first->prev = first->next = NULL;
    first->data = A[0];
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        t->prev = last;
        last = t;
    }
}

int Length(Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(Node *p, int pos, int x)
{
    Node *t;
    if (pos < 0 || pos > Length(p))
    {
        return;
    }
    if (pos == 0)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (Node *)malloc(sizeof(Node));
        t->data = x;
        t->prev=p;
        t->next=p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int Delete(Node *p,int pos){
    int x = -1;
    if(pos<0||pos>Length(p)){
        return x;
    }
    if(pos==1){
        p=p->next;
        x=first->data;
        free(first);
        first=p;
        if(p){
            p->prev=NULL;
        }
    }else{
        for(int i = 0; i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);

    }
    return x;
}

int main()
{
    int A[] = {10, 26, 23, 56};
    create(A, 4);
    insert(first,4,70);
    Delete(first,1);
    Display(first);
    return 0;
}