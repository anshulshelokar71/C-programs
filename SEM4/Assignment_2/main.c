#include "stack.h"
#include <math.h>
#include <limits.h>
#define MAX 20

// typedef struct arr
// {
//     int num;
//     int used;
// } arr;

typedef struct BST
{
    int *A;
    int size;
    int len;
} BST;

BST *init_BST(BST *t)
{
    t->size = MAX;
    t->len = 0;
    t->A = (int *)malloc(sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        t->A[i] = INT_MIN;
    }
    return t;
}

BST *insert_BST(BST *t, int data)
{
    if (t->len == 0)
    {
        t->A[t->len++] = data;
        return t;
    }
    int i = 0, j;
    while (t->A[i] != INT_MIN)
    {
        if (t->A[i] > data)
        {
            j = i;
            i = 2 * i + 1;
        }
        else if (t->A[i] < data)
        {
            j = i;
            i = 2 * i + 2;
        }
        else
        {
            printf("Duplicates are not allowed!!!");
            return t;
        }
    }
    if (t->A[j] > data)
    {
        t->A[2 * j + 1] = data;
    }
    else
    {
        t->A[2 * j + 2] = data;
    }
    t->len++;
    return t;
}

int levelwise(BST *t)
{
    int count = 0, j = 2, Complete = 1,nodes=0;
    for (int i = 0, k = 0; i <= j; i++)
    {
        if (t->A[i] != INT_MIN)
        {
            j = 2 * i + 2;

            printf("%d ", t->A[i]);
            nodes++;
            if (nodes==pow(2,k))
            {
                printf("\n");
                k++;
                nodes=0;
            }
            count++;
            if (count == t->len)

            {
                printf("\n");

                return Complete;
            }
        }
        else
        {
            if (t->A[(i - 2) / 2] != -1)
            {
                printf("%d ", -1);
                if (nodes == pow(2, k))
                {
                    printf("\n");
                    k++;
                    nodes=0;
                }
            }
            Complete = 0;
        }
    }
    printf("\n");
    return Complete;
}

int isComplete(BST *t)
{
    int count = 0, j = 2, Complete = 1;
    for (int i = 0; i <= j; i++)
    {
        if (t->A[i] != INT_MIN)
        {
            j = 2 * i + 2;
            count++;
            if (count == t->len)
            {
                return Complete;
            }
        }
        else
        {
            Complete = 0;
        }
    }
    return Complete;
}

void Ipreorder(BST *t)
{
    struct stack st;
    BST *p;
    int i = 0;
    create(&st, 100);
    while ((t->A[i] != INT_MIN) || !isEmpty(st))
    {
        if (t->A[i] != INT_MIN)
        {
            printf("%d ", t->A[i]);
            push(&st, i);
            i = 2 * i + 1;
        }
        else
        {
            i = pop(&st);
            i = 2 * i + 2;
        }
    }
}

void Iinorder(BST *t)
{
    struct stack st;
    BST *p;
    int i = 0;
    create(&st, 100);
    while ((t->A[i] != INT_MIN) || !isEmpty(st))
    {
        if (t->A[i] != INT_MIN)
        {
            push(&st, i);
            i = 2 * i + 1;
        }
        else
        {
            i = pop(&st);
            printf("%d ", t->A[i]);
            i = 2 * i + 2;
        }
    }
}

void Ipostorder(BST *t)
{
    struct stack a, b;
    BST *p = t;
    int i = 0;
    create(&a, 100);
    create(&b, 100);
    push(&a, i);
    while (!isEmpty(a))
    {
        i = pop(&a);
        push(&b, i);
        if (t->A[2 * i + 1] != INT_MIN)
        {
            push(&a, 2 * i + 1);
        }
        if (t->A[2 * i + 2] != INT_MIN)
        {
            push(&a, 2 * i + 2);
        }
    }
    while (!isEmpty(b))
    {
        printf("%d ", t->A[pop(&b)]);
    }
}

int main()
{
    BST t;
    BST *n = init_BST(&t);
    // n = insert_BST(n, 5);
    // n = insert_BST(n, 3);
    // n = insert_BST(n, 7);
    // n = insert_BST(n, 1);
    // n = insert_BST(n, 4);
    // n = insert_BST(n, 6);
    // n = insert_BST(n, 8);
    // Ipostorder(n);
    // Iinorder(n);
    // levelwise(n);
    // printf("\n%d",isComplete(n));
    // for (int i = 0; i < 10; i++)
    // {
    //     if (n->A[i] != INT_MIN)
    //         printf("%d", n->A[i]);
    // }
    int x;
    do
    {
        int m;
        printf("BST ARRAY IMPLEMENTATION:-\n");
        printf("Enter 1 for insert \n");
        printf("Enter 2 for isComplete\n");
        printf("Enter 3 for levelwise traversal\n");
        printf("Enter 4 for traverse\n");
        printf("Enter 5 for END\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter number to insert:");
            scanf("%d", &m);
            n = insert_BST(n, m);
            break;
        case 2:
            if (isComplete(n))
            {
                printf("Given BST is complete!!!");
            }
            else
            {
                printf("Given BST is not complete!!!");
            }
            break;
        case 3:
            printf("levelwise traversal : \n");
            levelwise(n);
            break;
        case 4:
            printf("Enter 1 for preorder\n");
            printf("Enter 2 for inorder\n");
            printf("Enter 3 for postorder\n");
            scanf("%d", &m);
            switch (m)
            {
            case 1:
                Ipreorder(n);
                break;
            case 2:
                Iinorder(n);
                break;
            case 3:
                Ipostorder(n);
                break;
            default:
                printf("Enter valid number\n");
                break;
            }
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (x != 5);

    return 0;
}
