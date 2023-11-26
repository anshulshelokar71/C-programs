#include<stdio.h>
int main(){

	int row;
	printf("Enter number of row : ");
	scanf("%d",&row);
	for(int i = 0; i<row;i++){
		for(int k = 1;k<=row-i;k++){
			printf("  ");
		}
		for(int j = 1;j<=2*i+1;j++){
			printf("%s","* ");	
		}
		printf("\n");
	
	}
	

	return 0;
}
