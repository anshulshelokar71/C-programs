#include <stdio.h>

int main() {
    float num1, num2, num3, sum;

    // Read three floating-point numbers from the user
    printf("Enter the first floating-point number: ");
    scanf("%f", &num1);

    printf("Enter the second floating-point number: ");
    scanf("%f", &num2);

    printf("Enter the third floating-point number: ");
    scanf("%f", &num3);

    // Calculate the sum
    sum = num1 + num2 + num3;

    // Print the result with only two digits after the decimal point
    printf("Sum: %.2f\n", sum);

    return 0;
}
