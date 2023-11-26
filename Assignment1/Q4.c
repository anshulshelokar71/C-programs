
#include<stdio.h>
#include<math.h>
int main(){
	int baseSal;
	float DA;
	printf("Input Base Salary : ");
	scanf("%d",&baseSal);
	if(baseSal>=10000 && baseSal<=20000){
		DA = 0.1*baseSal;
	}else if(baseSal>20000 && baseSal<=50000){
		DA = 0.15*baseSal;
	}else if(baseSal>50000 && baseSal<=100000){
		DA = 0.2*baseSal;
	}
	printf("DA = %f \n",DA);


	return 0;
}
