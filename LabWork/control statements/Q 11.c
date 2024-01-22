#include <stdio.h>
#include <ctype.h>

int main() {
    char character;

    do {
        // Read a character from the user
        printf("Enter a character (enter '*' to exit): ");
        scanf(" %c", &character);

        // Check if the entered character is '*'
        if (character == '*') {
            break;  // Exit the loop if '*' is entered
        }

        // Print the entered character and its ASCII value
        printf("Character: %c\n", character);
        printf("ASCII Value: %d\n", character);

        // Convert case if the character is an alphabet
        if (isalpha(character)) {
            if (islower(character)) {
                printf("Uppercase: %c\n", toupper(character));
            } else {
                printf("Lowercase: %c\n", tolower(character));
            }
        }

    } while (1);  // Infinite loop until '*' is entered

    printf("Program exited. Goodbye!\n");

    return 0;
}
