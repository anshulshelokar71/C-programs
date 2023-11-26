#include<stdio.h>
#include<math.h>
int main(){
	int radius;
	float area,circum;
	const float pi = 3.14;
	printf("Enter the radius of circle : ");
	scanf("%d",&radius);
	area = pi*radius*radius;
	circum = 2*pi*radius;
	printf("Area and Circumference of circle are %f sq.units & %f units respectively \n",area,circum);

	return 0;
}
