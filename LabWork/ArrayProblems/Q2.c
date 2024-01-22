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
		printf("%d ",arr[i]);
	}
	
	printf("\nThe array after reversing is:-\n");
	for (int i=9; i>=0; i--)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}

	
	
	
	
