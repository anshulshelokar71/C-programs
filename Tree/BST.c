#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node *root = NULL;

Node *RSearch(Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->data == key)
    {
        return t;
    }
    else if (t->data < key)
    {
        return RSearch(t->rchild, key);
    }
    else
    {
        return RSearch(t->lchild, key);
    }
}

Node *Insert(Node *t, int x)
{
    Node *r, *p, *q;
    q = t;
    r = NULL;
    if (t == NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->lchild = p->rchild = NULL;
        t = p;
        return t;
    }
    while (t)
    {
        r = t;
        if (t->data == x)
        {
            return NULL;
        }
        else if (t->data < x)
        {
            t = t->rchild;
        }
        else
        {
            t = t->lchild;
        }
    }
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->lchild = p->rchild = NULL;
    if (p->data < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
    return q;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int main()
{
    root = Insert(root, 2);
    Insert(root, 3);
    Insert(root, 5);
    Insert(root, 7);
    Inorder(root);
    Node *t = RSearch(root, 5);
    printf("%d", t->data);
    
    return 0;
}