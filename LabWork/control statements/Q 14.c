#include <stdio.h>

int main() {
    int n, sum = 0;
    float average;

    // Read the value of n from the user
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Calculate the sum using a for loop
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Calculate the average
    average = (float)sum / n;

    // Display the sum and average
    printf("Sum of numbers from 1 to %d: %d\n", n, sum);
    printf("Average of numbers from 1 to %d: %.2f\n", n, average);

    return 0;
}
