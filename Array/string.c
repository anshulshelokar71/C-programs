#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char str[100];
    char string[2147];
    fgets(str, 100, stdin);
    printf("%s", str);
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    printf("%d", strlen(str) - 1);
    for (int i = 0; i <= b; i++)
    {
    }

    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (str[i - 1] == 'B')
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}