#include <stdio.h>
#include <stdlib.h>
#include"header.h"

struct Node *push(struct Node *n,int x)
{
    struct Node *t,*top;
    top=n;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is Full\n");
        return NULL;
    }
    else
    {
        t->data = x;
        t->next = top;
        n = t;

        return n;
    }
}

struct Node* pop(struct Node *n)
{
    struct Node *top=n;
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *p;
        p = top;
        n = n->next;
        x = p->data;
        printf("Number poped out of stack is %d\n",x);
        free(p);
    }
    return n;
}

struct Node * peek(struct Node *n,int index)
{
    int x = -1;
    if (n == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct Node *p,*top=n;
        p = top;
        for (int i = 0; p != NULL && i < index - 1; i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            x = p->data;
            printf("Number at %d index is %d\n",index,x);
        }else{
            printf("Index not found\n");
        }
        return n;
    }
}

void Display(struct Node *n)
{
    struct Node *p;
    p = n;
    while (n!=NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}



