#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
struct Node *front,*rear;
void init();
void display();
int dequeue();
void enqueue(int x);