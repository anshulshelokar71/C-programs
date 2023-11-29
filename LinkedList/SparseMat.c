#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int col;
    int x;
    struct Node *next;
} Node;

typedef struct Sparse
{
    int m;
    int n;
    int num;
    Node *ele;
} Sparse;

void create(Sparse *s)
{
    int r;
    printf("Enter the dimensions:");
    scanf("%d %d", &s->m, &s->n);

    s->ele = (Node *)malloc((s->m) * sizeof(Node));
    for (int k = 0; k < s->m; k++)
    {
        s->ele[k].next = NULL;
    }
    printf("Enter the number of non-zero elements:");
    scanf("%d", &s->num);
    printf("Enter the elements:");
    for (int i = 0; i < s->num; i++)
    {
        Node *t;
        t = (Node *)malloc(sizeof(Node));
        scanf("%d %d %d", &r, &t->col, &t->x);
        t->next = NULL;
        if (s->ele[r].next == NULL)
        {
            s->ele[r].next = t;
        }
        else
        {
            Node *p = s->ele[r].next;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

void Display(Sparse *s)
{
    for (int i = 0; i < s->m; i++)
    {
        Node *p = s->ele[i].next;

        for (int j = 0; j < s->n; j++)
        {
            if (p && j == p->col)
            {
                printf("%d ", p->x);
                p = p->next;
            }
            else
            {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

Sparse *add(Sparse *s1, Sparse *s2)
{
    Sparse *sum;
    sum = (Sparse *)malloc(sizeof(Sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->ele = (Node *)malloc((sum->m) * sizeof(Node));
    int i, j, k;

    for ( int a = 0; a < sum->m; a++)
    {
        sum->ele[a].next = NULL ; i = j = k = 0;
        Node *q1, *q2;
        q1 = s1->ele[a].next;
        q2 = s2->ele[a].next;
        while (q1 != NULL && q2 != NULL)
        {
            Node *t;
            t = (Node *)malloc(sizeof(Node));
            if (q1->col < q2->col)
            {
                t->col = q1->col;
                t->x = q1->x;
                t->next = NULL;
                if (sum->ele[a].next == NULL)
                {
                    sum->ele[a].next = t;
                }
                else
                {
                    Node *p = sum->ele[a].next;
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    p->next = t;
                }
                q1 = q1->next;
            }
            else if (q1->col > q2->col)
            {
                t->col = q2->col;
                t->x = q2->x;
                t->next = NULL;
                if (sum->ele[a].next == NULL)
                {
                    sum->ele[a].next = t;
                }
                else
                {
                    Node *p = sum->ele[a].next;
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    p->next = t;
                }
                q2 = q2->next;
            }
            else
            {
                t->col = q1->col;
                t->x = q1->x + q2->x;
                t->next = NULL;
                if (sum->ele[a].next == NULL)
                {
                    sum->ele[a].next = t;
                }
                else
                {
                    Node *p = sum->ele[a].next;
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    p->next = t;
                }
                q1 = q1->next;
                q2 = q2->next;
            }
        }
        if (q1 != NULL)
        {
            Node *p = sum->ele[a].next;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = q1;
        }
        else
        {
            Node *p = sum->ele[a].next;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = q2;
        }
    }
    return sum;
}

    int main()
    {

        Sparse s1,s2,*ss;
        create(&s1);
        create(&s2);
        printf("First Sparse Matrix\n");
        Display(&s1);
        printf("First Sparse Matrix\n");
        Display(&s2);
        ss=add(&s1,&s2);
        printf("Sum of Sparse Matrix\n");
        Display(ss);


        return 0;
    }