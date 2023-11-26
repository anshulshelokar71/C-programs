#include<stdio.h>
#include<math.h>
int main(){
	int n;
	printf("Enter size of an array :");
	scanf("%d",&n);
	int arr[n];
	printf("Input array is : ");
	for(int i = 0; i<n;i++){
		scanf("%d",&arr[i]);
		//printf("%d ",arr[i]);
	}
	
	printf("Reversed array is : ");
	for(int i = 0;i<n/2;i++){
		int temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}
	for(int i = 0; i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
