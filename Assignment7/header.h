struct Node
{
    int data;
    struct Node *next;
};
struct Node *push(struct Node *n,int x);
struct Node *peek(struct Node *n,int index);
struct Node *pop(struct Node *n);
void Display(struct Node *n);