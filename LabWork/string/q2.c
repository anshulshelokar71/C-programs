#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    static char *token;

    if (str != NULL) {
        token = str;
    } else {
        if (token == NULL) {
            return NULL;
        }
    }

    char *start = token;
    char *end = strpbrk(start, delim);

    if (end != NULL) {
        *end = '\0';
        token = end + 1;
    } else {
        token = NULL;
    }

    return start;
}

int main() {
    char inputString[100];
    char delimiter[10];

    // Get input string from user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character if present
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Get delimiter from user
    printf("Enter a delimiter: ");
    scanf("%s", delimiter);

    // Tokenize and display the result
    char *token = my_strtok(inputString, delimiter);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delimiter);
    }

    return 0;
}
