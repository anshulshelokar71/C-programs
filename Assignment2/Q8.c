#include<stdio.h>
#include<math.h>
int main(){
	for(int i = 2;i<=100;i++){
		int count=0; 
		for(int k =2;k<=i/2;k++){
			if(i%k==0 && i!=k){
				count++;
				break;
			}
		}
		if(count==0)
		{
			printf("%d \n",i);
		}
	}

	return 0;
}
