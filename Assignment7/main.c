#include "logic.c"
int main()
{

    struct Node *stack;
    stack = NULL;
start:
    int a,n;
    printf("Enter the number for associated operation\n1.push\n2.pop\n3.peek\n4.display\n5.end\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("enter number to push:");
        scanf("%d", &n);
        stack = push(stack, n);
        goto start;
    case 2:
        stack = pop(stack);
        goto start;
    case 3:
        printf("enter index to peek:");
        scanf("%d", &n);
        stack = peek(stack, n);
        goto start;
    case 4:
        Display(stack);
        goto start;
    case 5:
        printf("Program ended successfully!!!\n");
        goto end;
    end:
        return 0;
    }
    
    
    return 0;
}