#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    long int MIS;
    char name[100];
    struct Node *lpointer;
    struct Node *rpointer;
} Node;

Node *root = NULL;

Node *CreateNode(int MIS, char *name)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->lpointer = t->rpointer = NULL;
    t->MIS = MIS;
    strcpy(t->name, name);
    return t;
}
void initBST(Node *n)
{
    n->lpointer = n->rpointer = NULL;
}

void insertNode(Node *n, long int num, char s[])
{
    Node *t, *p;
    p = n;
    t = CreateNode(num, s);
    if (n == NULL)
    {
        root = t;
        return;
    }
    Node *prev;
    while (p)
    {
        prev = p;
        if (num < p->MIS)
        {
            p = p->lpointer;
        }
        else if (num > p->MIS)
        {
            p = p->rpointer;
        }
        else
        {
            return;
        }
    }
    if (num < prev->MIS)
    {
        prev->lpointer = t;
    }
    else if (num > prev->MIS)
    {
        prev->rpointer = t;
    }
    return;
}

void insert_rec(Node *p,int mis,char name[]){

    if(!p){
        root = CreateNode(mis,name);
    }
    if(mis>p->MIS){
        insert_rec(p->rpointer,mis,name);
    }else if(mis<p->MIS){
        insert_rec(p->lpointer,mis,name);
    }

    return p;
}

int Count(Node *p)
{
    int lc,rc;
    if(!p){
        return 0;
    }
    lc = Count(p->lpointer);
    rc = Count(p->rpointer);
    return lc+rc+1;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lpointer);
        printf("[%d %s]", p->MIS, p->name);
        Inorder(p->rpointer);
    }
}

void Preorder(Node *p)
{
    if (p)
    {
        printf("[%d %s]", p->MIS, p->name);
        Preorder(p->lpointer);
        Preorder(p->rpointer);
    }
}

void Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lpointer);
        Postorder(p->rpointer);
        printf("[%d %s]", p->MIS, p->name);
    }
}

int search(Node *p, int key)
{
    while (p)
    {
        if (p->MIS == key)
        {
            return 1;
        }
        else if (p->MIS > key)
        {
            p = p->lpointer;
        }
        else
        {
            p = p->rpointer;
        }
    }
    // printf("MIS is not registered\n");
    return -1;
}

Node* Insucc(Node *p) {
    
    while(p && p->lpointer) {
        p = p->lpointer;
    }
    return p;
}

Node *removeNode(Node* p, long int key) {
    if(!p)
        return p;
    if(key == p->MIS) {
        if(!p->rpointer && !p->lpointer) {
            Node *temp = p;
            p = NULL;
            free(temp);
            return NULL;
        } else if(!p->rpointer && p->lpointer) {
            Node *temp = p->lpointer;
            free(p);
            return temp;
        } else if(p->rpointer && !p->lpointer) {
            Node *temp = p->rpointer;
            free(p);
            return temp;
        } else {
            Node *temp = Insucc(p->rpointer);
            p->MIS = temp->MIS;
            p->rpointer = removeNode(p->rpointer, p->MIS);
        }
    } else if(key < p->MIS){
        p->lpointer = removeNode(p->lpointer, key);
    }
    else if(key > p->MIS) {
        p->rpointer = removeNode(p->rpointer, key);
    }

    return p;
}

int main()
{
    char *name;
    char ch;
    int n, m;
    do
    {
        printf("BST FUNCTIONS:-\n");
        printf("Enter 1 for insert node\n");
        printf("Enter 2 for Count\n");
        printf("Enter 3 for Search MIS\n");
        printf("Enter 4 for removing a node with MIS\n");
        printf("Enter 5 for traverse\n");
        printf("Enter 6 for END\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter MIS to insert:");
            scanf("%d", &m);
            printf("Enter name:");
            scanf("%s", name);
            insertNode(root, m, name);
            break;
        case 2:
            printf("Count of MIS: %d\n", Count(root));
            break;
        case 3:
            printf("Enter MIS to be searched: ");
            scanf("%d", &m);
            int x = search(root, m);
            (x == 1) ? printf("MIS found!!!\n") : printf("MIS is not found\n");
            break;
        case 4:
            printf("Enter MIS to be deleted:");
            scanf("%d", &m);
            root = removeNode(root, m);
            break;
        case 5:
            printf("Enter 1 for preorder\n");
            printf("Enter 2 for inorder\n");
            printf("Enter 3 for postorder\n");
            scanf("%d",&m);
            switch (m)
            {
            case 1:
                Preorder(root);
                break;
            case 2:
                Inorder(root);
                break;
            case 3:
                Postorder(root);
                break;
            default:
                printf("Enter valid number\n");
                break;
            }
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (n != 6);

    return 0;
}
