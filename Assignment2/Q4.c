#include<stdio.h>
#include<math.h>
int main(){
	int dec,sum=0;
	printf("Enter a number :");
	scanf("%d",&dec);
	int q,r,i=0,count=0;
	q = dec;
	
	while(q>=1){
		r = q%2;
		q/=2;
		sum = sum + pow(10,i)*r;
		i++;
		if(r==1){
			count++;
		}
	}
	printf("%d \n Number of 1's : %d \n",sum,count);
	return 0;
}
