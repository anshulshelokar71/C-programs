#include <stdio.h>

int main() {
    // Get user input
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Determine divisibility
    int divisibleBy5 = (number % 5 == 0);
    int divisibleBy6 = (number % 6 == 0);

    // Output results
    printf("Is %d divisible by 5 and 6? %s\n", number, (divisibleBy5 && divisibleBy6) ? "true" : "false");
    printf("Is %d divisible by 5 or 6? %s\n", number, (divisibleBy5 || divisibleBy6) ? "true" : "false");
    printf("Is %d divisible by 5 or 6, but not both? %s\n", number, (divisibleBy5 ^ divisibleBy6) ? "true" : "false");

    return 0;
}
