#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	printf("Enter 3 numbers :");
	scanf("%d %d %d", &a,&b,&c);
	(a>b&&a>c) ? printf("%d is largest among three numbers \n",a) : 
	(b>a&&b>c) ? printf("%d is largest among three numbers \n",b) :
	(c>a&&c>b) ? printf("%d is largest among three numbers \n",c): printf("All numbers are equal \n");

	return 0;
}
