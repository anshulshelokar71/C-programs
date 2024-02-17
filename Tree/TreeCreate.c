#include"stack.h"

Node *root=NULL;

void TreeCreate(){
    Node *p,*t;
    int x;
    struct Queue q; 
    create(&q,100);
    printf("Enter the root value:");
    scanf("%d",&x);
    root = (Node *)malloc(sizeof(Node));
    root->data=x;
    root->rchild=root->lchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter the left child of %d :",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (Node*)malloc(sizeof(Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            enqueue(&q,t);
            p->lchild=t;
        }
        printf("Enter the right child of %d :",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (Node*)malloc(sizeof(Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            enqueue(&q,t);
            p->rchild=t;
        }
    }

}

void preorder(Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void postorder(Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void IPreorder(Node *p){
    struct stack st;
    Node *t;
    createStack(&st,100);
    while(p || !isEmptyStack(st)){
        if(p!=NULL){
            printf("%d",p->data);
            push(&st,p);
            p=p->lchild;
        }else{
            p = pop(&st);
            p=p->rchild;
        }
    }
}


int main(){

    TreeCreate();
    IPreorder(root);
    return 0;
}