#include<stdio.h>
int isPalindrome(int a[],int n){
    for(int i =0;i<=n/2;i++){
        if(a[i]!=a[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    printf("enter size of array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i <n;i++){
        scanf("%d",&arr[i]);
    }
    isPalindrome(arr,n)?printf("Palindrome"):printf("Not Palindrome");
    return 0;
}