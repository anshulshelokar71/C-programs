#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

Node* init_bst(Node *n){
    n->lchild=n->rchild=NULL;
    return n;
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

void IPreorder(Node *p){
    struct stack st;
    Node *t;
    createStack(&st,100);
    while(p || !isEmptyStack(st)){
        if(p!=NULL){
            printf("%d ",p->data);
            push(&st,p);
            p=p->lchild;
        }else{
            p = pop(&st);
            p=p->rchild;
        }
    }
}

void IInorder(Node *p){
    struct stack st;
    Node *t;
    createStack(&st,100);
    while(p || !isEmptyStack(st)){
        if(p!=NULL){
            push(&st,p);
            p=p->lchild;
            
        }else{
            p = pop(&st);
            printf("%d ",p->data);

            p=p->rchild;
        }
    }
}

void IPostorder(Node *p){
    struct stack st;
    long int temp;
    Node *t;
    createStack(&st,100);
    while(p || !isEmptyStack(st)){
        if(p!=NULL){
            push(&st,p);
            p=p->lchild;
            
        }else{
            temp = (long int)pop(&st);
            if(temp>0){
                push(&st,(Node*)(-temp));
                p = ((Node*)temp)->rchild;
            }else{
                printf("%d ",((Node*)temp)->data);
                p = NULL;
            }
        }
    }
}

void levelOrder(Node *t){
    queue q;
    create(&q,100);

    printf("%d ",t->data);
    enqueue(&q,t);

    while(!isEmpty(q)){
        t = dequeue(&q);
        if(t->lchild){
            printf("%d ",t->lchild->data);
            enqueue(&q,t->lchild);
        }
        if(t->rchild){
            printf("%d ",t->rchild->data);
            enqueue(&q,t->rchild);
        }
    }
}

int isComplete(Node *t){
    queue q;
    create(&q,100);
    enqueue(&q,t);
    int notComplete=0;
    while(!isEmpty(q)){
        Node *p = dequeue(&q);
        if(p->lchild){
            if(notComplete==1) return 0;
            enqueue(&q,p->lchild);
        }else{
            notComplete = 1;
        }
         if(p->rchild){
            if(notComplete==1) return 0;
            enqueue(&q,p->rchild);
        }else{
            notComplete=1;
        }
    }
    return 1;
}

int main(){
    int arr[] ={4,2,6,7,8,1,3,5};
    Node*root=NULL;
    for(int i=0;i<8;i++){
        root=Insert(root,arr[i]);
    }
    IPreorder(root);

    return 0;
}
