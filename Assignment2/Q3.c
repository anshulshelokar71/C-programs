#include<stdio.h>
#include<math.h>
int main(){
	int num,sum=0;
	printf("Enter a number :");
	scanf("%d",&num);
	int q,r,i=0;
	q = num;
	while(q>0){
		r = q%10;
		q/=10;
		if(i%2==0){
			sum+=r;
		}
		i++;
	}
	printf("%d \n",sum);


	return 0;
}
