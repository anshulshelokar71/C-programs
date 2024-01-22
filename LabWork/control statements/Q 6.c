#include <stdio.h>
#include <math.h>

// Function to calculate simple interest
float calculateSimpleInterest(float principal, float rate, float time) {
    return (principal * rate * time) / 100.0;
}

// Function to calculate compound interest
float calculateCompoundInterest(float principal, float rate, float time) {
    return principal * (pow(1 + rate / 100.0, time) - 1);
}

int main() {
    float principal, rate, time;
    
    // Read principal, rate, and time from the user
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    
    printf("Enter rate of interest: ");
    scanf("%f", &rate);
    
    printf("Enter time (in years): ");
    scanf("%f", &time);

    // Calculate and display simple interest
    float simpleInterest = calculateSimpleInterest(principal, rate, time);
    printf("Simple Interest: %.2f\n", simpleInterest);

    // Calculate and display compound interest
    float compoundInterest = calculateCompoundInterest(principal, rate, time);
    printf("Compound Interest: %.2f\n", compoundInterest);

    return 0;
}
