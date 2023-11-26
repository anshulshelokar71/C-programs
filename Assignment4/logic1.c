#include "header1.h"
struct {
	int km;
	int meter;

} s1,s2,s3;

void Read(){
	printf("Enter the first distance in kms and meters:");
	scanf("%d %d",&s1.km,&s1.meter);
	printf("Enter the second distance in kms and meters:");
	scanf("%d %d",&s2.km,&s2.meter);
	return;
}
void Display(){
	printf("First distance is %d km %d meters\n",s1.km,s1.meter);
	printf("Second distance is %d km %d meters\n",s2.km,s2.meter);
	return;
}

void Add(){

	s3.meter = s1.meter+s2.meter;
	s3.km = s1.km+s2.km+(s3.meter/1000);
	if(s3.meter>=1000)
		s3.meter-=1000;
	printf("The sum of two distances is: %d kms %d meters\n",s3.km,s3.meter);
	return;
}

void Diff(){

	if((s1.km+s1.meter/1000.0)>(s2.km+s2.meter/1000.0)){
		s3.km = ((s1.km+s1.meter/1000.0)-(s2.km+s2.meter/1000.0));
		s3.meter = ((s1.km+s1.meter/1000.0)-(s2.km+s2.meter/1000.0))*1000-s3.km*1000;
	}else{
		s3.km = ((s2.km+s2.meter/1000.0)-(s1.km+s1.meter/1000.0));
		s3.meter = ((s2.km+s2.meter/1000.0)-(s1.km+s1.meter/1000.0))*1000-s3.km*1000;
	}
	printf("The difference of two distances is: %d kms %d meters\n",s3.km,s3.meter);

	return;
}

void menu(){
	printf("************MAIN MENU*****************\n1.Read the distances\n2.Display the distances\n3.Add the distances\n4.Subtract the distances\n5.EXIT\n");

	int i = 1;
	while(i){
		int n;
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			Read();
			break;
		case 2:
			Display();
			break;
		case 3:
			Add();
			break;
		case 4:
			Diff();
			break;
		case 5:
			i = 0;
			printf("Exited Successfully!!!\n");
			break;
			
			
		}
	}

}
