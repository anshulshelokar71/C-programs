#include<stdio.h>
#include<math.h>
int main(){
	int r1,c1,r2,c2;
	printf("Enter number of rows and columns of matrix 1 : ");
	scanf("%d %d",&r1,&c1);
	printf("Enter number of rows and columns of matrix 2 : ");
	scanf("%d %d",&r2,&c2);
	int mat1[r1][c1],mat2[r2][c2],sum[r1][c1],sub[r1][c1],mul[r1][c2];
	printf("Enter elements of matrix 1 : ");
	for(int i = 0;i<r1;i++){
			for(int j = 0;j<c1;j++){
				scanf("%d",&mat1[i][j]);
			}
	}
	printf("Enter elements of matrix 2 : ");
	for(int i = 0;i<r2;i++){
			for(int j = 0;j<c2;j++){
				scanf("%d",&mat2[i][j]);
			}
	}
	//-------------------------------Addition & Subtraction-------------------------
	if(r1==r2&&c1==c2){
		printf("Addition matrix is \n");
		for(int i = 0;i<r1;i++){
			for(int j = 0;j<c1;j++){
				sum[i][j] = mat1[i][j]+mat2[i][j];
				sub[i][j] = mat1[i][j]-mat2[i][j];
				printf("%d ",sum[i][j]);
			}
			printf("\n");
		}
		printf("\nSubtraction matrix is \n");
		for(int i = 0;i<r1;i++){
			for(int j = 0;j<c1;j++){
				printf("%d ",sub[i][j]);
			}
			printf("\n");
		}
			
	}else{
		printf("operation is not applicable!!!\n");
	}
	printf("\nMultiplication matrix is \n");
	//-------------------------------Multiplication----------------------------------
	if(c1==r2){
		for(int i = 0;i<r1;i++){
			for(int j = 0;j<c2;j++){
				mul[i][j] = 0;
				for(int k = 0;k<c1;k++){
					mul[i][j]= mul[i][j]+mat1[i][k]*mat2[k][j];
					
				}
				printf("%d ",mul[i][j]);
			}
			printf("\n");
		}
	
	}
	return 0;
}
