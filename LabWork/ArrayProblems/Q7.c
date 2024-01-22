#include<stdio.h>
#include<math.h>

int main()
{
	int size=10;
	int arr[size];
	for (int i=0; i<10;i++)
	{
		int t;
		printf("Enter an element:-\n");
		scanf("%d",&t);
		arr[i]=t;
	}
	
	printf("The array is:-\n");
	for (int i=0; i<size; i++)
	{
		printf("%d,",arr[i]);
	}
	
	for ( int i=0;i<size;i++)  
    {  
        for (int j=i+1;j<size;j++)  
        {  
          
            if (arr[i]==arr[j])  
            {  
                 
                for (int k=j;k<size-1;k++)  
                {  
                    arr[k]=arr[k+1];  
                }  
               
                size=size-1;  
                  
       
                j=j-1;      
            }  
        }  
    } 
    
    printf("\nThe array after removing the element is:-\n");
	for (int i=0; i<size; i++)
	{
		printf("%d,",arr[i]);
	}
	
	return 0;
}

	
    
     
