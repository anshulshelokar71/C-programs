#include<stdio.h>
#include<math.h>
#define size 10

int main()
{
	int arr[size];
	for (int i=0; i<10;i++)
	{
		int t;
		printf("Enter an element:-\n");
		scanf("%d",&t);
		arr[i]=t;
	}
	
	printf("The array is:-\n");
	for (int i=0; i<10; i++)
	{
		printf("%d ",arr[i]);
	}
	int arr2[size];
	
	int n,dir;
	printf("Enter the number of positions to be shifted:-\n");
	scanf("%d",&n);
	printf("Enter 1 for right shifting and 2 for left shifting:-\n");
	scanf("%d",&dir);
	
	if(dir==1)
	{
		for (int i=0; i<=(size-n-1);i++)
		{
			arr2[i+n]=arr[i];
			
		}
		for (int j=size-n; j<size;j++)
		{
			arr2[size-j]=arr[j];
		}
	}
	
	else if (dir==2)
	{
		for (int i=0;i<=(n-1); i++)
		{
			arr2[size-i-1]=arr[i];
		}
		for (int i=n; i<size-1; i++)
		{
			arr2[i-n]=arr[i];
		}
	}
	
	printf("The array the shiting of elements is:-\n");
	for (int i=0; i<10; i++)
	{
		printf("%d,",arr2[i]);
	}
	
	return 0;
}

	
	
			
