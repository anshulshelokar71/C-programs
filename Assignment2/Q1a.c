#include<stdio.h>
#include<math.h>
int main(){
	int n,sum=0;
	printf("Enter a number :");
	scanf("%d",&n);
	int i = 1;
	while(i<=n){
		sum+=i;
		i++;
	}
	printf("Sum of %d natural numbers is %d \n",n,sum);
	return 0;
}
