#include<stdio.h>
#include<math.h>
int main(){
	int i=97;
	printf("ASCII values for lowercase alphabets are : \n");
	while(i>='a' && i<='z'){
		printf("%d \n",i);
		i++;
	}
	int j = 65;
	printf("ASCII values for uppercase alphabets are : \n");
	while(j>='A' && j<='Z'){
		printf("%d \n",j);
		j++;
	}

	return 0;
}
