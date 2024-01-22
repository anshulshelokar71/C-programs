#include <stdio.h>

int main() {
    int m, n;

    // Read values for m and n from the user
    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Ensure that m is less than or equal to n
    if (m > n) {
        printf("Error: m should be less than or equal to n.\n");
        return 1; // Exit the program with an error code
    }

    // Print odd numbers from m to n using a loop
    printf("Odd numbers from %d to %d:\n", m, n);
    for (int i = m; i <= n; ++i) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
