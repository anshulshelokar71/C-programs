#include <stdio.h>
#include<string.h>

int countOccurrences(char *str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char inputString[100];
    char character;

    // Get input string from user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character if present
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Get character to count
    printf("Enter a character to count: ");
    scanf(" %c", &character);

    // Count occurrences and display the result
    int result = countOccurrences(inputString, character);
    printf("The character '%c' occurs %d times in the string.\n", character, result);

    return 0;
}
