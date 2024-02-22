#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

typedef struct Node{
    char data;
    struct Node*left,*right;
}Node;

int prec(char c){
    if(c=='+'||c=='-'){
        return 2;
    }else if(c=='*'||c=='/'){
        return 3;
    }else if(c=='('){
        return 1;
    }
    return 0;
}

Node *CreateNode(char c)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->left = t->right = NULL;
    t->data = c;
    return t;
}

Node* insertNode(Node *n, char c,int x)
{
    Node *t, *p;
    p = n;
    t = CreateNode(c);
    if (n == NULL)
    {
        n = t;
        return n;
    }
    Node *prev=n;
   
    if (x==1)
    {
        prev->right = t;
    }
    else if (x==0)
    {
        prev->left = t;
    }
    return prev;
}


Node *ExpressionTree(char s[]){
    Node *root=NULL;
    stack st1,st2;
    create(&st1,100);
    create(&st2,100);
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='('||s[i]==')'){
            if(prec(s[i])<prec(stackTop(st1))){
                char c = pop(&st1);
                root=insertNode(root,c,1);
                c = pop(&st2);
                root=insertNode(root,c,1);
                char b = pop(&st2);
                root = insertNode(root,b,0);
                Node*p=root;
                push(&st2,p);
            }else{
                push(&st1,s[i++]);
            }
        }else{
            push(&st2,s[i++]);
        }
    }
}

int main(){
    char s[]="(1+2)";
    stack st1,st2;
    create(&st1,100);
    create(&st2,100);
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='('||s[i]==')'){
            push(&st1,s[i++]);
        }else{
            push(&st2,s[i++]);
        }
    }
    Display(st1);
    Display(st2);
    return 0;
}