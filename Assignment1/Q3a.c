#include<stdio.h>
#include<math.h>
int main(){
	char alph;
	printf("Enter an alphabet :");
	scanf("%c", &alph);
	if(alph=='a'||alph=='e'||alph=='i'||alph=='o'||alph=='u'||
	   alph=='A'||alph=='E'||alph=='I'||alph=='O'||alph=='U'
	){
		printf("Given alphabet is an vowel!!!");
	}else{
		printf("Given alphabet is a consonant!!!");
	}
	

	return 0;
}
