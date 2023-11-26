#include<stdio.h>
int main(){

	int row,num=1;
	printf("Enter number of row : ");
	scanf("%d",&row);
	for(int i = 0; i<row;i++){
		for(int j = 1;j<=i+1;j++){
			j%2==0 ? printf("%d",1) : printf("%d",0);
			//printf(" ");
		}
		for(int k = 1;k<=row-i;k++){
			printf("  ");
			
		}
		for(int m = 1;m<=i+1;m++){
			m%2==0 ? printf(" %d",1) : printf(" %d",0);
			
		}
		printf("\n");
		
	
	}
	return 0;
}
