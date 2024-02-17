#include"queue.h"
struct stack{
    int size;
    int top;
    Node **s;
};

void createStack(struct stack *st,int n){
    st->size=n;
    st->top=-1;
    st->s=(Node**)malloc(st->size*sizeof(Node*));
}

void push(struct stack *st,Node* x){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }else{
        (st->top)++;
        st->s[st->top] = x;
    }
}

Node* pop(struct stack *st){
    Node* x = NULL;
    if(st->top==-1){
        printf("Stack underflow");
    }else{
        x = st->s[st->top--];
        // st->top--;
    }
    return x;
}

int isEmptyStack(struct stack st){
    return st.top==-1;
}

