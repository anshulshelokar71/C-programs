#include<stdio.h>

int main(){
    int arr[20];
    int pos,neg,odd,even,zeros;
    pos=neg=odd=even=zeros=0;
    printf("Enter nos");
    for(int i = 0;i<20;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>0)pos++;
        else if(arr[i]<0)neg++;
        else zeros++;
        if(arr[i]%2==0)even++;
        else odd++;
    }
    printf("Number of Pos nos:%d\n",pos);
    printf("Number of Neg nos:%d\n",neg);
    printf("Number of Even nos:%d\n",even);
    printf("Number of Odd nos:%d\n",odd);
    printf("Number of Zeros nos:%d\n",zeros);

    return 0;
}