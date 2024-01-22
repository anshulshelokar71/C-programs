#include <stdio.h>

int main() {
    float floatValue;

    // Read a floating-point value from the user
    printf("Enter a floating-point value: ");
    scanf("%f", &floatValue);

    // Print the value in exponential format with different precision
    printf("Value entered: %f\n", floatValue);
    
    // Precision: two decimal places
    printf("Value in exponent form (2 decimal places): %.2e\n", floatValue);

    // Precision: four decimal places
    printf("Value in exponent form (4 decimal places): %.4e\n", floatValue);

    // Precision: eight decimal places
    printf("Value in exponent form (8 decimal places): %.8e\n", floatValue);

    return 0;
}
