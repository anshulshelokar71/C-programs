#include<stdio.h>
#include<math.h>
#define size 10

int main()
{
	int arr[size];
	for (int i=0; i<10;i=i+1)
	{
		int t;
		printf("Enter an element:-\n");
		scanf("%d",&t);
		arr[i]=t;
	}
	
	printf("The array is:-\n");
	for (int i=0; i<10; i=i+1)
	{
		printf("%d,",arr[i]);
	}
	
	int sum=0;
	for (int j=0; j<10; j=j+1)
	{
		sum=sum+pow(arr[j],2);
	}
		
	printf("\nThe sum of square of all the elements in the array is %d\n",sum);
	
	return 0;
}

	
	
