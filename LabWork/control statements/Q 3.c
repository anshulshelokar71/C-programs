#include <stdio.h>
#include <ctype.h>

int count_vowels(const char *text) {
    int vowel_count = 0;

    while (*text != '\0') {
        char current_char = *text;

        // Convert the character to lowercase to simplify the check
        current_char = tolower(current_char);

        // Check if the current character is a vowel
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' ||
            current_char == 'o' || current_char == 'u') {
            vowel_count++;
        }

        // Move to the next character in the text
        text++;
    }

    return vowel_count;
}

int main() {
    char text[100];

    // Read text from the user
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Count the number of vowels
    int result = count_vowels(text);

    // Print the result
    printf("No. of vowels: %d\n", result);

    return 0;
}
