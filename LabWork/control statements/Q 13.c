#include <stdio.h>
#include <ctype.h>

int main() {
    char input;

    // Read a character or number from the user
    printf("Enter a character or number: ");
    scanf(" %c", &input);

    // Check if the input is a digit
    if (isdigit(input)) {
        printf("You entered a digit: %c\n", input);
    } else {
        // It's a character

        // Print ASCII value
        printf("ASCII Value: %d\n", input);

        // Check if the character is uppercase or lowercase
        if (isupper(input)) {
            printf("Uppercase character: %c\n", input);
        } else if (islower(input)) {
            printf("Lowercase character: %c\n", input);
        } else {
            printf("It's a character, but not uppercase or lowercase.\n");
        }
    }

    return 0;
}
