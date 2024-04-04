# include <stdio.h>
# include <stdlib.h>
# include "STACK.c"



int isOp(char c) {
    if(c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')' )
        return 1;
    return 0;
}

int precedence(char c) {
    if(c == '*' || c == '/')
        return 10;
    else if(c == '+' || c == '-')
        return 5;
    else 
        return 0;
}

void inorder(node *n) {
    if(n) {
        inorder(n->l);
        printf("%c ", n->c);
        inorder(n->r);
    }
}

void preorder(node *n) {
    if(n) {
        printf("%c ", n->c);
        preorder(n->l);
        preorder(n->r);
    }
}

void postorder(node *n) {
    if(n) {
        postorder(n->l);
        postorder(n->r);
        printf("%c ", n->c);
    }
}



int main() {

    char exp[50];
    stack *st_op;
    stack *st_ch;
    init_stack(&st_ch);
    init_stack(&st_op);
    node *p1, *p2, *op;
    printf("Enter INFIX expression : ");
    scanf("%s", exp);

    for(int i = 0; exp[i] != '\0'; i++) {

        if(isOp(exp[i])) {
            
            if(exp[i] == '(')
                push(&st_op, '(');
            else if(exp[i] == ')') {
                while(st_op && top(&st_op) != '(') {
                    p2 = pop(&st_ch);
                    p1 = pop(&st_ch);
                    op = pop(&st_op);
                    op->l = p1;
                    op->r = p2;
                    push_node(&st_ch, op);  
                }
                pop(&st_op);
            } else {
                if(precedence(exp[i]) > precedence(top(&st_op))) {
                    push(&st_op, exp[i]);
                } else {
                    while(precedence(exp[i]) <= precedence(top(&st_op))) {
                        p2 = pop(&st_ch);
                        p1 = pop(&st_ch);
                        op = pop(&st_op);
                        op->l = p1;
                        op->r = p2;
                        push_node(&st_ch, op);
                    }
                    push(&st_op, exp[i]);
                }
            }

        } else {
            push(&st_ch, exp[i]);
        }
    }

    while(!isEmpty(&st_op)) {
        p2 = pop(&st_ch);
        p1 = pop(&st_ch);
        op = pop(&st_op);
        op->l = p1;
        op->r = p2;
        push_node(&st_ch, op);
    }

    node *ans = pop(&st_ch);
    printf("Inorder : ");
    inorder(ans);
    printf("\nPreorder : ");
    preorder(ans);
    printf("\nPostorder : ");
    postorder(ans);

    return 0;
}