#include<stdio.h>
#include<math.h>
int main(){

	int r1,c1,sumRow[r1],sumCol[c1];
	printf("Enter number of rows and columns of matrix : ");
	scanf("%d %d",&r1,&c1);
	int mat1[r1][c1];
	printf("Enter elements of matrix : ");
	for(int i = 0;i<r1;i++){
		sumRow[i] = 0;
			for(int j = 0;j<c1;j++){
				scanf("%d",&mat1[i][j]);
				printf("%d ",mat1[i][j]);
				sumRow[i]+=mat1[i][j];
				
			}
			printf("\n");
	}
	printf("Sum of elements of row \n");
	for(int i = 0;i<r1;i++){
		printf("%d \n",sumRow[i]);
	}
	for(int j = 0;j<c1;j++){
		sumCol[j] = 0;
			for(int i = 0;i<r1;i++){
				sumCol[j]+=mat1[i][j];
				
			}
	}
	printf("Sum of elements of column \n");
	for(int i = 0;i<c1;i++){
		printf("%d ",sumCol[i]);
	}
	printf("\n");

	return 0;
}
