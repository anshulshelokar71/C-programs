#include<stdio.h>
#include<math.h>
int main(){

	int row;
	printf("Enter number of row : ");
	scanf("%d",&row);
	for(int i = 0; i<row;i++){
		for(int k = 1;k<=row-i;k++){
			printf(" ");
		}
		for(int j = 0;j<=i;j++){
			double f = tgamma(i+1)/(tgamma(i-j+1)*tgamma(j+1));
			int d = (int)f;
			printf("%d ",d);	
		}
		printf("\n");
	
	}
	

	return 0;
}
