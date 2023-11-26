#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
	int x;
	float sinx=0;
	printf("Enter a number : ");
	scanf("%d",&x);
	float inp = x*(pi/180);
	for(int n =1,j = 0;n<100;n+=2,j++){
		sinx = sinx+pow(-1,j)*pow(inp,n)/tgamma(n+1);
	}
	printf("%lf \n",sinx);
	return 0;
}
