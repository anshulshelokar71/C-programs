#include<stdio.h>
#include<math.h>
int main(){
	float cel,fah;
	printf("Enter temperature in Fahrenheit : ");
	scanf("%f",&fah);
	cel = (5.0 / 9)*(fah-32);
	printf("Temperature in Celsius is %f C \n",cel);

	return 0;
}

