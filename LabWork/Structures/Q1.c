#include <stdio.h>
typedef struct name
{
    char FirstName[20];
    char MiddleName[20];
    char LastName[20];

} Name;
typedef struct DOB
{
    int day;
    int month;
    int year;
} DateOfBirth;
typedef struct mark
{
    int Eng;
    int math;
    int compSci;
} Marks;
struct Student
{
    int RollNo;
    Name name;
    char Gender[10];
    DateOfBirth DOB;
    Marks marks;
}std[5];

float avg[5];