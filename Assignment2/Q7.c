#include<stdio.h>
#include<math.h>
int main(){
	int a,b,gcd=0,lcm=0;
	printf("Enter two numbers : ");
	scanf("%d %d",&a,&b);
	
	int LCM(int a,int b){
		for(int i = 1;i<=a;i++){
			for(int j = 1;j<=b;j++){
				if(a*j==b*i){
					return a*j;
				}
			}
		}
		//return a*b;
	}
	printf("LCM of given numbers is %d \n",LCM(a,b));
	if(a>b){
		for(int i = 1;i<=b;i++){
			if(a%i==0&&b%i==0){
				i>gcd ? gcd=i:gcd==1;
			}
		}
		
		printf("GCD of given numbers is %d \n",gcd);
	
	}else{
		for(int i = 1;i<=a;i++){
			if(a%i==0&&b%i==0){
				i>gcd ? gcd=i :gcd==1;
			}
		}
		
		printf("GCD of given numbers is %d \n",gcd);
	}

	return 0;
}
