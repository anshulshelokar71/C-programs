#include<stdio.h>

float circleArea(float rad){
	float area = 3.14 * rad * rad;
	return area;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void factorial(){
	for(int i = 1 ; i<=5 ; i++){
		int fact = 1;
		for(int j = 1 ; j<=i ; j++){
			fact = fact*j;
		}	
		printf("%d\n", fact);
	}
}

int main(){
	float rad = 5;
	printf("%f", circleArea(rad));
	int a = 4; 
	int b = 5;
	swap(&a, &b);
	printf("\n%d %d \n", a, b);
	factorial();
	return 0;
}
