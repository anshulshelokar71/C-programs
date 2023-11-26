#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *q;
    q = (struct Node*)malloc(sizeof(struct Node));
    if(q==NULL){
        printf("Queue is Full");
    }else{
        q->data=x;
        q->next=NULL;
        if(front==NULL){
            front = rear = q;
        }
        rear->next=q;
        rear = q;
    }
    return;

}

int dequeue(){
    int x =-1;
    if(front==NULL){
        printf("Queue is empty");
    }else{
        struct Node *p;
        p = front;
        front=front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display(){
    struct Node *p;
    p = front;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(6);
    dequeue();
    display();
}