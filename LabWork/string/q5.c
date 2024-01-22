#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary and return the binary representation in a string
char *decimalToBinary(int num) {
    // Calculate the maximum number of bits needed for the binary representation
    int maxBits = sizeof(int) * 8;

    // Allocate memory for the binary string
    char *binary = (char *)malloc(maxBits + 1);
    if (binary == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the binary string
    for (int i = 0; i < maxBits; i++) {
        binary[i] = '0';
    }
    binary[maxBits] = '\0';

    // Convert decimal to binary
    int index = maxBits - 1;
    while (num > 0 && index >= 0) {
        binary[index] = (num % 2) + '0';
        num /= 2;
        index--;
    }

    return binary;
}

int main() {
    int decimalNum;

    // Get input decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Convert to binary and display the result
    char *binaryResult = decimalToBinary(decimalNum);

    printf("Binary representation: %s\n", binaryResult);

    // Free allocated memory
    free(binaryResult);

    return 0;
}
