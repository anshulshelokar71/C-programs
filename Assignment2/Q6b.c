#include<stdio.h>
int main(){

	int row,num=1;
	printf("Enter number of row : ");
	scanf("%d",&row);
	for(int i = 0; i<row;i++){
		for(int j = 1;j<=i+1;j++){
			printf("%d",num);
			printf(" ");
			num++;	
		}
		printf("\n");
	
	}
	

	return 0;
}
