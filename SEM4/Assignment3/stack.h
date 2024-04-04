#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node*left,*right;
}Node;

typedef struct stack{
    int size;
    int top;
    char *s;
}stack;

typedef struct stack1{
    int size;
    int top;
    Node **s;
}stack1;

void create(stack *st,int n){
    st->size=n;
    st->top=-1;
    st->s=(char*)malloc(st->size*sizeof(char));
}

void create1(stack1 *st,int n){
    st->size=n;
    st->top=-1;
    st->s=(Node**)malloc(st->size*sizeof(Node*));
}

void Display(stack st){
    for(int i = st.top;i>=0;i--){
        char c=st.s[i];
        printf("%c ",c);
    }
    printf("\n");
}

void push(stack *st,char x){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

void push1(stack1 *st,Node* x){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}


char pop(stack *st){
    char x = -1;
    if(st->top==-1){
        printf("Stack underflow");
    }else{
        x = st->s[st->top--];
        // st->top--;
    }
    return x;
}

Node* pop1(stack1 *st){
    Node *x=NULL;
    if(st->top==-1){
        printf("Stack underflow");
    }else{
        x = st->s[st->top--];
        // st->top--;
    }
    return x;
}

int peek(stack st,int index){
    int x = -1;
    if(st.top-index+1<0){
        printf("Invalid Index \n");
    }else{
        x = st.s[st.top-index+1];
    }
    return x;
}

int isEmpty(stack st){
    return st.top==-1;
}

int isEmpty1(stack1 st){
    return st.top==-1;
}

int isFull(stack st){
    return st.top==st.size-1;
}

char stackTop(stack st){
    char x = -1;
    if(!isEmpty(st)){
        x = st.s[st.top];
    }
    return x;
}

Node* stackTop1(stack1 st){
    Node* x=NULL;
    if(!isEmpty1(st)){
        x = st.s[st.top];
    }
    return x;
}