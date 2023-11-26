#include<stdio.h>
int main(){

	char c;
	printf("Enter the character : ");
	scanf("%c",&c);
	if(c>=65&&c<=90){
		c=c+32;
		printf("%c \n",c);
	}else if(c>=97&&c<=122){
		c = c-32;
		printf("%c \n",c);
	}else{
		printf("Not an alphabet!!!");
	}
	

	return 0;
}
