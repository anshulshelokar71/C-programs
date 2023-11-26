#include<stdio.h>
#include<math.h>
int main(){
	int r;
	printf("Enter order of a square matrix : ");
	scanf("%d",&r);
	int mat[r][r],lt[r][r],ut[r][r];
	printf("Enter elements of matrix : ");
	for(int i = 0;i<r;i++){
			for(int j = 0;j<r;j++){
				scanf("%d",&mat[i][j]);
				printf("%d ",mat[i][j]);
			}
			printf("\n");
	}
	printf("Lower triangular Matrix :\n");
	for(int i = 0;i<r;i++){
			for(int j = 0;j<r;j++){
				if(i!=j&&i<j){
					lt[i][j] = 0;
				}else{
					lt[i][j]=mat[i][j];
				}
				printf("%d ",lt[i][j]);
			}
			printf("\n");
	}
	printf("Upper triangular Matrix :\n");
	for(int i = 0;i<r;i++){
			for(int j = 0;j<r;j++){
				if(i!=j&&i>j){
					ut[i][j] = 0;
				}else{
					ut[i][j]=mat[i][j];
				}
				printf("%d ",ut[i][j]);
			}
			printf("\n");
	}

	return 0;
}
