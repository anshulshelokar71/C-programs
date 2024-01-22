#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int print_random(int lower, int upper) 
{ 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
    
} 

int main()
{

	
	int arr[10];
	for (int i=0; i<10; i++)
	{
		int num=print_random(50,100);
		arr[i]=num;
	}
	
	printf("The array is:-\n");
	for (int j=0; j<10; j++)
	{
		printf("%d,",arr[j]);
	}
	printf("\n");
	
	return 0;
}

	
