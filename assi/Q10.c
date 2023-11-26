#include<stdio.h>
#include<math.h>
int main(){
	int vow,cons,dig,blsp;
	vow=cons=dig=blsp=0; 
	char str[100];
	printf("Enter any string : \n");
	scanf("%[^\n]s", str);
	for(int i = 0;str[i]!='\0' ;i++){
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'
			   ||str[i]=='I'||str[i]=='O'||str[i]=='U')
			{
				vow++;
			}else{
				cons++;
			}
		}else if(str[i]>='0' && str[i]<='9'){
			dig++;
		}else if(str[i]==' '){
			blsp++;
		}
		
	}
	printf("Number of vowels in input string is : %d \n",vow);
	printf("Number of consonants in input string is : %d \n",cons);
	printf("Number of digits in input string is : %d \n",dig);
	printf("Number of blank-space in input string is : %d \n",blsp);

	return 0;
}
