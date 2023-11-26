#include<stdio.h>
#include<math.h>
int main(){
	int n,max1=0,max2=0;
	float avg;
	printf("Enter total number of integres to read :");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>max1){
			max2=max1;
			max1=arr[i];
		}
		
	}

	avg = (max1+max2)/2.0;
	printf("Average of largest two of given numbers is %f \n",avg);

	return 0;
}
