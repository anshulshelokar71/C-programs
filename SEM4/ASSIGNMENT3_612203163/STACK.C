# include <stdio.h>
# include <stdlib.h>


typedef struct node {
    char c;
    struct node *l;
    struct node *r;
}node;


typedef struct stack {
    node *n;
    struct stack *next;
}stack;


void init_stack(stack **s) {
    *s = NULL;
}

int isEmpty(stack **s) {
    if((*s) == NULL)
        return 1;
    return 0;
}

void push(stack **s, char c) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->c = c;
    newnode->l = NULL;
    newnode->r = NULL;
    stack *p = (stack*)malloc(sizeof(stack));
    p->n = newnode;
    p->next = *s;
    *s = p;
}

node* pop(stack **s) {
    stack *p = *s;
    *s = p->next;
    return p->n; 
}

void push_node(stack **s, node *nde) {
    stack *p = (stack*)malloc(sizeof(stack));
    p->n = nde;
    p->next = *s;
    *s = p;
}

char top(stack **s) {
    if(*s == NULL)
        return '$';
    return (*s)->n->c;
}