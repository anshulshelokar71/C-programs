#include <stdio.h>

int main()
{
    int c[10];

    int a[] = {45, 50, 80, 80, 80};
    int b[] = {30, 40, 60, 75, 80};

    int i, j, k;
    i = j =k= 0;
    while (i < 5 && j < 5)
    {
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }else if(a[i]==b[j]){
            c[k++]=b[j++];
            // i++;
        }else{
             c[k++]=b[j++];
        }
    }
    for(;i<5;i++)c[k++]=a[i];
    for(;j<5;j++)c[k++]=b[j];
    for(int i = 0;i<10;i++){
        printf("%d ",c[i]);
    }

    return 0;
}