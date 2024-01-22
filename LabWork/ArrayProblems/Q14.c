#include<stdio.h>
#include<stdlib.h>

int main(){

    int arr[100];
    for(int i = 0; i<100;i++){
        arr[i]= rand()%1000+1;
    }
    int new_arr[100];
    for(int i = 0,j=0;i<100;i++){
        if(arr[i]%8==0||arr[i]%15==0){
            new_arr[j]=arr[i];
            printf("%d ",new_arr[j++]);
        }
    }
    
    return 0;
}