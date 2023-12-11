#include <stdio.h>
typedef struct frac
{
    int num;
    int den;
} Frac;

Frac f1, f2;
int compare(float fr1, float fr2)
{
    if (fr1 < fr2)
    {
        return -1;
    }
    else if (fr1 > fr2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    float fr1, fr2;
    printf("Enter first fraction");
    scanf("%d %d", &f1.num, &f1.den);
    printf("Enter second fraction");
    scanf("%d %d", &f2.num, &f2.den);
    fr1 = (float)f1.num / f1.den;
    fr2 = (float)f2.num / f2.den;
    printf("%d", compare(fr1, fr2));
    return 0;
}
