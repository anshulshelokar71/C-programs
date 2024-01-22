#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct Node
{
    int data;
    struct Node *next;
} SLL;

void init_SLL(SLL *n)
{
    n = NULL;
    return;
}

void append(SLL *n, int x)
{
    SLL *p, *t;
    p = n;
    while (p->next != NULL)
    {
        p = p->next;
    }
    t = (SLL *)malloc(sizeof(SLL));
    t->data = x;
    t->next = NULL;
    p->next = t;
    p = t;
}

void traverse(SLL *n)
{
    while (n)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void remove_duplicates(SLL *n)
{
    SLL *p, *q, *r;
    p = r = n;
    q = n->next;
    while (p != NULL)
    {
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                r->next = q->next;
                free(q);
                q = r->next;
            }
            else
            {
                r = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    SLL L1;
    init_SLL(&L1);
    append(&L1, 1);
    append(&L1, 2);
    append(&L1, 3);
    append(&L1, 2);
    append(&L1, 1);
    traverse(&L1);
    remove_duplicates(&L1);
    traverse(&L1);
    return 0;
}