#include <stdio.h>
#include <math.h>

int main() {
    float floatingNumber;
    int integralPart, rightmostDigit;

    // Read a floating-point number from the user
    printf("Enter a floating-point number: ");
    scanf("%f", &floatingNumber);

    // Extract the integral part of the number
    integralPart = (int)floatingNumber;

    // Calculate the rightmost digit of the integral part
    rightmostDigit = integralPart % 10;

    // Display the rightmost digit of the integral part
    printf("Rightmost digit of the integral part: %d\n", abs(rightmostDigit));

    return 0;
}
