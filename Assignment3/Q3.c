#include<stdio.h>
#include<math.h>
int main(){
	int n,num,ind;
	printf("Enter size of an array :");
	scanf("%d",&n);
	int arr[n+1];
	printf("Input array is : ");
	for(int i = 0; i<n;i++){
		scanf("%d",&arr[i]);
		//printf("%d ",arr[i]);
	}
	printf("Enter number to be inserted : ");
	scanf("%d",&num);
	printf("Enter index at which number is to be inserted : ");
	scanf("%d",&ind);
	if(ind==n){
		arr[ind] = num;
	}else{
		for(int i = n-1;i>=ind;i--){
			arr[i+1] = arr[i];
		}
		arr[ind] = num;
		
	}
	for(int i = 0; i<n+1;i++){
			//scanf("%d",&arr[i]);
			printf("%d ",arr[i]);
		}
	return 0;
}
