#include <stdio.h>

// Constants for HRA and TA rates
#define HRA_RATE 0.10
#define TA_RATE 0.05

int main() {
    float basicPay, salary;

    // Read basic pay from the user
    printf("Enter the basic pay: ");
    scanf("%f", &basicPay);

    // Calculate HRA and TA
    float hra = basicPay * HRA_RATE;
    float ta = basicPay * TA_RATE;

    // Calculate total salary
    salary = basicPay + hra + ta;

    // Display the salary components and total salary
    printf("Basic Pay: %.2f\n", basicPay);
    printf("HRA: %.2f\n", hra);
    printf("TA: %.2f\n", ta);
    printf("Total Salary: %.2f\n", salary);

    return 0;
}
