#include<stdio.h>
#include<math.h>
#define size 10

int main()
{
	float arr[size];
	for (int i=0; i<10;i=i+1)
	{
		float t;
		printf("Enter an element:-\n");
		scanf("%f",&t);
		arr[i]=t;
	}
	
	float num;
	printf("Enter the number which is to be searched:-\n");
	scanf("%f",&num);
	
	int k=0;
	int found=0;
	while(k<10)
	{
		if (arr[k]==num)
		{
			printf("The entered number is found in the array at the position %d\n",k+1);
			break;
			found=1;
		}
		else
		{
			k=k+1;
		}
	}
	
	if((k==10)&&(found==0))
	{
		printf("The ordered element is not found.\n");
		
	}
	
	return 0;
}

	
