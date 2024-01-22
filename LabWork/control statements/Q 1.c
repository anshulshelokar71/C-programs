#include <stdio.h>

int main() {
    int numbers[10];

    // Read 10 integers
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; ++i) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Display the numbers in groups of three
    printf("Displaying numbers in groups of three:\n");
    for (int i = 0; i < 10; i += 3) {
        printf("%d", numbers[i]);

        // Print the next two numbers with commas
        for (int j = 1; j < 3 && i + j < 10; ++j) {
            printf(", %d", numbers[i + j]);
        }

        printf("\n");
    }

    return 0;
}
