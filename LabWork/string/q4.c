#include <stdio.h>

// Function to find the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM of two numbers
int lcm(int a, int b) {
    // LCM = (|a * b|) / GCD(a, b)
    return (a / gcd(a, b)) * b;
}

int main() {
    int num1, num2;

    // Get input numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate and display the GCD and LCM
    int resultGCD = gcd(num1, num2);
    int resultLCM = lcm(num1, num2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, resultGCD);
    printf("The LCM of %d and %d is: %d\n", num1, num2, resultLCM);

    return 0;
}
