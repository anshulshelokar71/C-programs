#include <stdio.h>
typedef struct date
{
    int day;
    int month;
    int year;
} Date;
Date d;

int isLeap(int a)
{
    if ((a % 400 == 0) || (a % 100 != 0) && (a % 4 == 0))
    {
        return 1;
    }
    return 0;
}
int isValid(int a, int b, int c)
{
    if (isLeap(c))
    {
        if (b == 2)
        {
            if (a > 29)
            {
                printf("Invalid date");
                return 0;
            }
        }
    }
    else
    {
        if (b == 2)
        {
            if (a > 28)
            {
                printf("Invalid date");
                return 0;
            }
        }
    }
    if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
    {
        if (a > 31)
        {
            printf("Invalid date");
            return 0;
        }
    }
    else if (b == 4 || b == 6 || b == 9 || b == 11)
    {
        if (a > 30)
        {
            printf("Invalid date");
            return 0;
        }
    }
    return 1;
}

void read()
{
    printf("Enter the date:");
    scanf("%d%d%d", &d.day, &d.month, &d.year);
    if(isValid(d.day, d.month, d.year))printf("%d/%d/%d",d.day,d.month,d.year);
}

int main()
{
    read();
    return 0;
}