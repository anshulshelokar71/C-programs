#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node *list;

void init(list *head)
{
    *head = NULL;
    return;
}

void append(list *head, int ele)
{
    node *newnode, *p;
    newnode = (node *)malloc(sizeof(node));
    if (newnode)
    {
        newnode->data = ele;
        newnode->next = NULL;
    }
    else
    {
        return;
    }
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    p = *head;
    while (p->next)
    {
        p = p->next;
    }
    p->next = newnode;
    return;
}

void insert_beg(list *head, int ele)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode)
    {
        newnode->data = ele;
        newnode->next = NULL;
    }
    else
    {
        return;
    }
    newnode->next = *head;
    *head = newnode;
    return;
}

void remove_duplicates(list *head)
{
    if (*head == NULL)
    {
        return;
    }

    node *p = *head;
    while (p != NULL)
    {
        node *q = p;

        while (q->next != NULL)
        {
            if (p->data == q->next->data)
            {
                node *temp = q->next;
                q->next = q->next->next;
                free(temp);
            }
            else
            {
                q = q->next;
            }
        }

        p = p->next;
    }
}

void reverse_even(list *head)
{
    list temp;
    init(&temp);

    node *p = *head;
    while (p)
    {
        if ((p->data) % 2 == 0)
        {
            insert_beg(&temp, p->data);
        }
        p = p->next;
    }

    p = *head;
    node *q = temp;
    while (p && q)
    {
        if ((p->data) % 2 == 0)
        {
            p->data = q->data;
            q = q->next;
        }
        p = p->next;
    }

    p = temp;
    while (p)
    {
        node *temp_node = p;
        p = p->next;
        free(temp_node);
    }
}

int palindrome(list head)
{
    node *p = head;
    list rev_list;
    init(&rev_list);
    while (p)
    {
        insert_beg(&rev_list, p->data);
        p = p->next;
    }
    p = head;
    node *q = rev_list;
    while (p && q)
    {
        if (p->data != q->data)
        {
            return 0;
        }
        p = p->next;
        q = q->next;
    }
    return 1;
}

void traverse(list head)
{
    node *p;
    p = head;
    printf("[ ");
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf(" ]");
    return;
}

int main()
{

    list L1;
    init(&L1);
    append(&L1, 1);
    append(&L1, 2);
    append(&L1, 3);
    append(&L1, 4);
    append(&L1, 5);
    append(&L1, 4);
    append(&L1, 1);
    traverse(L1);

    if (palindrome(L1))
    {
        printf("\nEntered list is Palindrome");
    }
    else
    {
        printf("\nEntered list is NOT a Palindrome");
    }

    reverse_even(&L1);
    printf("\nReverse Even List : ");
    traverse(L1);

    remove_duplicates(&L1);
    printf("\nList after removing duplicates : ");
    traverse(L1);

    return 0;
}
