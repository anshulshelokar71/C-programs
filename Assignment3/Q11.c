#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int count,rep; 
	char str[20];
	printf("Input String is : ");
	scanf("%s",str);
	for(int i = 0; i<strlen(str);i++){
		count=0;
		rep=0;
		for(int k = 0; k <i;k++){
			if(str[i]==str[k]){
				rep++;
			}
		}
		if(rep==0){
			for(int j = 0; j<strlen(str);j++){
				if(str[i]==str[j]){
					count++;	
				}
			}
			printf("Frequency of %c : %d \n",str[i],count);
		}
	}

	return 0;
}
