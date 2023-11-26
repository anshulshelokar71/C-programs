#include<stdio.h>
#include<math.h>
int main(){

	int r1,c1,sum=0;
	printf("Enter number of rows and columns of matrix : ");
	scanf("%d %d",&r1,&c1);
	int mat1[r1][c1];
	printf("Enter elements of matrix : ");
	for(int i = 0;i<r1;i++){
			for(int j = 0;j<c1;j++){
				scanf("%d",&mat1[i][j]);
				if(i==j){
					sum+=mat1[i][j];
				}
			}
	}
	printf("Sum of diagonal entries is equal to %d \n",sum);
	
	return 0;
}
