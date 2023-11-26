#include<stdio.h>
#include<math.h>
int main(){
	int n,ind;
	printf("Enter size of an array :");
	scanf("%d",&n);
	int arr[n];
	printf("Input array is : ");
	for(int i = 0; i<n;i++){
		scanf("%d",&arr[i]);
		//printf("%d ",arr[i]);
	}
	//printf("Enter number to be inserted : ");
	//scanf("%d",&num);
	printf("Enter index at which number is to be deleted : ");
	scanf("%d",&ind);
	for(int i = ind ; i<n-1;i++){
		arr[i] = arr[i+1];
	}
	for(int i=0;i<n-1;i++ ){
		printf("%d ",arr[i]);
	}
	return 0;
}
