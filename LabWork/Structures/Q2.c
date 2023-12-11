#include "Q1.c"
#include <string.h>
void studentInfo()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the information of student %d :\n", i + 1);
        printf("Enter the roll number :");
        scanf("%d", &std[i].RollNo);
        printf("Enter Name of student:");
        scanf("%s", std[i].name.FirstName);
        scanf("%s", std[i].name.MiddleName);
        scanf("%s", std[i].name.LastName);
        printf("Enter Date of Birth of student:");
        scanf("%d", &std[i].DOB.day);
        scanf("%d", &std[i].DOB.month);
        scanf("%d", &std[i].DOB.year);
        printf("Enter marks of 3 subjects:(Eng,Math and CS)");

        scanf("%d", &std[i].marks.Eng);
        scanf("%d", &std[i].marks.math);
        scanf("%d", &std[i].marks.compSci);
        avg[i]=(std[i].marks.Eng+std[i].marks.math+std[i].marks.compSci)/3.0;
    }
}

void Display(char name1[], char name2[], char name3[])
{
    int i = -1;
    // float avg;
    for (int j = 0; j < 5; j++)
    {
        if (!strcmp(name1, std[j].name.FirstName) && !strcmp(name2, std[j].name.MiddleName) && !strcmp(name3, std[j].name.LastName))
        {
            i = j;
        }
    }
    if (i == -1)
    {
        printf("No such student exists!");
        return;
    }
    else
    {
        printf("Information of student %d :\n", i + 1);
        printf("Roll number : %d\n", std[i].RollNo);
        printf("Name: %s %s %s\n", std[i].name.FirstName, std[i].name.MiddleName, std[i].name.LastName);
        printf("Date of Birth: %d %d %d\n", std[i].DOB.day, std[i].DOB.month, std[i].DOB.year);
        printf("Marks of 3 subjects:(Eng,Math and CS): \n");

        printf("%d \n", std[i].marks.Eng);
        printf("%d \n", std[i].marks.math);
        printf("%d \n", std[i].marks.compSci);
        // avg = std[i].marks.Eng + std[i].marks.math + std[i].marks.compSci;
        
        printf("Average marks : %f\n", avg[i]);
    }
}

int main()
{
    char fname[20], mname[20], lname[20];
    studentInfo();
    printf("Enter the name of student:");
    scanf("%s %s %s", &fname, &mname, &lname);
    Display(fname, mname, lname);
    printf("List of students securing less than 40% marks");
    return 0;
}