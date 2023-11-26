#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
	int x;
	float cosx=0;
	printf("Enter a number : ");
	scanf("%d",&x);
	float inp = x*(pi/180);
	for(int n =0,j = 0;n<100;n+=2,j++){
		cosx = cosx+pow(-1,j)*pow(inp,n)/tgamma(n+1);
	}
	printf("%lf \n",cosx);
	return 0;
}
