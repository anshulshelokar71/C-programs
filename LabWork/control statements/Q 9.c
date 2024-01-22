#include <stdio.h>

int main() {
    int number;

    // Read an integer from the user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Display the value in decimal, octal, and hexadecimal notation
    printf("Decimal: %d\n", number);
    printf("Octal:   %o\n", number);
    printf("Hexadecimal:   %x\n", number);

    return 0;
}
