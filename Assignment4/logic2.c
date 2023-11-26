#include "header2.h"
void studentInfo(){
	for(int i = 0; i<5 ; i++){
		printf("Enter the information of student %d :\n",i+1);
		printf("Enter the roll number :");
		scanf("%d",&std[i].RollNum);
		printf("Enter Name of student:");
		scanf("%s",std[i].Name.FirstName);
		scanf("%s",std[i].Name.MiddleName);
		scanf("%s",std[i].Name.LastName);
		printf("Enter Date of Birth of student:");
		scanf("%d",&std[i].DOB.day);
		scanf("%d",&std[i].DOB.month);
		scanf("%d",&std[i].DOB.year);
		printf("Enter marks of 3 subjects:(Eng,Math and CS)");
		for(int j = 0;j<3;j++)
		scanf("%d",&std[i].marks[j]);
	}
}
void DisplayInfo(){	
	for(int i = 0; i<5 ; i++){
		float avg = 0;
		printf("Information of student %d :\n",i+1);
		printf("Roll number : %d\n",std[i].RollNum);
		printf("Name: %s %s %s\n",std[i].Name.FirstName,std[i].Name.MiddleName,std[i].Name.LastName);
		printf("Date of Birth: %d %d %d\n",std[i].DOB.day,std[i].DOB.month,std[i].DOB.year);
		printf("Marks of 3 subjects:(Eng,Math and CS): \n");
		for(int j = 0;j<3;j++){
			printf("%d \n",std[i].marks[j]);
			avg += std[i].marks[j];
	
		}
		printf("Average marks : %f\n",avg/3.0);
	}
}
