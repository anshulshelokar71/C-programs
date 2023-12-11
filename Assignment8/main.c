#include <stdio.h>
#include"logic.c"

int main()
{

    struct Node q1;
    int n,e;
start:
    printf("Enter number to do associate operation\n1.enqueue\n2.dequeue\n3.display\n4.End\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        /*enqueue*/
        printf("Enter number: ");
        scanf("%d", &e);
        enqueue(e);
        goto start;
    case 2:
        /*dequeue*/
        printf("%d\n",dequeue());
        goto start;
    case 3:
        /*display*/
        display();
        goto start;

    case 4:
        /*display*/
        printf("Program ended successfully!!!");
        goto end;

    end:
        return 0;
    }
}
