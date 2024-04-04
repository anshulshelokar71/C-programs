#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '(')
    {
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

Node *ExpressionTree(char s[])
{
    // Node *root=NULL;
    stack st1;
    stack1 st2;
    create(&st1, 100);
    create1(&st2, 100);
    Node *t, *t1, *t2;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            push(&st1, s[i]);
        }

        else if (s[i]!=')'&& (prec(s[i]) == 0))
        {
           
            t = CreateNode(s[i]);
            push1(&st2, t);
        }
        else if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-')
        {
            while (!isEmpty(st1) && stackTop(st1) != '(' && (prec(stackTop(st1)) >= prec(s[i])))
            {
                t = CreateNode(stackTop(st1));

                t1 = pop1(&st2);

                t2 = pop1(&st2);

                t->left = t2;
                t->right = t1;

                push1(&st2, t);
            }

            push(&st1, s[i]);
        }
        else if (s[i] == ')')
        {
            while (!isEmpty(st1) && stackTop(st1) != '(')
            {
                t = CreateNode(stackTop(st1));
                pop(&st1);
                t1 = stackTop1(st2);
                pop1(&st2);
                t2 = stackTop1(st2);
                pop1(&st2);
                t->left=t2;
                t->right=t1;
                push1(&st2,t);
            }
            pop(&st1);
        }
        i++;
    }
    t = stackTop1(st2);
    return t;
}

void Inorder(Node *n){
    if(n){
        Inorder(n->left);
        printf("%c ",n->data);
        Inorder(n->right);
    }
}

int main()
{
    char s[] = "(1+4)";
    Node *root=ExpressionTree(s);
    Inorder(root);
    return 0;
}