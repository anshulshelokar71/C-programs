#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
	float x;
	float ex=0;
	printf("Enter a number : ");
	scanf("%f",&x);
	for(int n =0,j = 0;n<100;n++,j++){
		ex = ex+pow(x,n)/tgamma(n+1);
	}
	printf("%lf \n",ex);
	return 0;
}
