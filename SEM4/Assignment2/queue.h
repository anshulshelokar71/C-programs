#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}Node;
typedef struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;//array(*Q) of (Node*)
}queue;
void create(struct Queue *q,int s){
    q->size = s;
    q->front=q->rear=-1;
    q->Q = (Node**)malloc(s*sizeof(Node*));
}
void enqueue(struct Queue*q,Node* x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full\n");
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
    return;
}

Node* dequeue(struct Queue*q){
    Node* x = NULL;
    if(q->rear==q->front){
        printf("Queue is empty\n");
    }else{
        q->front=(q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}

