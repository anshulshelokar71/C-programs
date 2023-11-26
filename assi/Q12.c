#include<stdio.h>
#include<string.h>
int main(){
//---------------------------------------------------------w/o using library function------------------------------------
	char str[20];
	printf("Input string is(either uppercase or lowercase): ");
	scanf("%s",str);
	for(int i = 0; i<strlen(str);i++){
		if(str[i]>=65&&str[i]<=90){
			str[i]=str[i]+32;
			printf("%c",str[i]);
		}else if(str[i]>=97&&str[i]<=122){
			str[i] = str[i]-32;
			printf("%c",str[i]);
		}else{
			printf("%c",str[i]);
		}
	}
	printf("\n");

	
//--------------------------------------------------------------using library function--------------------------------------------
	//if(str[0]>=65&&str[0]<=90){
//		printf("%s",strlwr(str));
//	}else{
//		printf("%s",strupr(str));
//	}
	return 0;
}
