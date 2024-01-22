#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

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

    // Print prime numbers from m to n using a loop and the isPrime function
    printf("Prime numbers from %d to %d:\n", m, n);
    for (int i = m; i <= n; ++i) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
