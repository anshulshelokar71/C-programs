#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int arr[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    last = head;
    head->data = arr[0];
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node *t, *last;
    last = head;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (head == NULL)
    {
        head = last = t;
    }
    else
    {   
        while(p!=NULL){
            last = p;
            p=p->next;
        }
        
        last->next = t;
        last = t;
    }
}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*last;
    last = head;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(p==NULL){
        head = last = t;
    }else{
        while(p && x>p->data){
            last = p;
            p=p->next;
        }
        if(p==head){
            t->next=head;
            head = t;
        }else{
        t->next = last->next;
        last->next = t;
        }
        
    }
}

int Sum_LL(struct Node *p)
{
    int sum = 0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int count(struct Node*p)
{
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Rcount(struct Node*p)
{
    if(p==0){
        return 0;
    }
    return 1+Rcount(p->next);
    
}

int maxLL(struct Node *p)
{
    int max = 0;
    while (p)
    {
        
        if(max<p->data){
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

int RmaxLL(struct Node *p)
{
    int x = 0;
    if(p==NULL)
        return INT_MIN;
    x = RmaxLL(p->next);
    return x>(p->data) ? x:p->data;
}

int LinearSearch(struct Node *p,int x)
{
    int index = 0;
    while(p){
        if(x == p->data){
            return ++index;
        }
        index++;
        p=p->next;
        
    }
    return -1;
}

int binSearch(struct Node *p,int x)
{
    int l=0,h=count(p)-1,index=0;
    int mid;
    while (l<h)         
    {
        index = 0;
        p = head;
        mid=(l+h)/2;
        while(p&&index<mid){
            p=p->next;
            index++;
        }
        if(x>p->data){
            l = mid+1;
        }else if(x<p->data){
            h = mid-1;
        }else{
            return mid;
        }

        
    }
    return -1;
    
}

int DeleteNode(struct Node *p,int index)
{
    struct Node *q = NULL;
    int x = -1;
    if(index<1 || index>count(p)){
        return -1;
    }
    if(index==1){
        x = head->data;
        p = head;
        head=head->next;
        free(p);
        return x;
    }
    for(int i = 0; i<index-1 && p; i++){
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;

}

int main()
{
    // int A[] = {3, 4, 5, 7, 9};
    // create(A,5);
    SortedInsert(head,10);
    SortedInsert(head,1);
    SortedInsert(head,6);
    // printf("%d\n",Sum_LL(head));
    // printf("%d\n",count(head));
    // printf("%d\n",Rcount(head));
    // printf("%d\n",RmaxLL(head));
    // printf("%d\n",LinearSearch(head,10));
    // printf("%d\n",binSearch(head,10));
    printf("%d\n",DeleteNode(head,3));

    // Insert(head,5,10);
    // InsertLast(head, 8);
    // InsertLast(head, 16);
    // InsertLast(head, 17);
    // InsertLast(head, 47);
    Display(head);
    return 0;
}