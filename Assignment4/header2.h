#include<stdio.h>
typedef struct Name{
		char FirstName[20];
		char MiddleName[20];
		char LastName[20];
	}Name;
struct student{
	int RollNum;
	Name Name;
	struct DOB{
		int day;
		int month;
		int year;
		
	}DOB;
	int marks[3];

};

void studentInfo();
void DisplayInfo();
struct student std[5];

