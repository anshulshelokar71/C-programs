#include <stdio.h>

int main() {
    int lower_limit = 1;
    int upper_limit = 200;
    
    int count_even = 0;
    int sum_even = 0;

    for (int i = lower_limit; i <= upper_limit; ++i) {
        // Check if the number is even
        if (i % 2 == 0) {
            count_even++;
            sum_even += i;
        }
    }

    // Print the count and sum of even numbers
    printf("Count of even numbers between %d and %d: %d\n", lower_limit, upper_limit, count_even);
    printf("Sum of even numbers between %d and %d: %d\n", lower_limit, upper_limit, sum_even);

    return 0;
}
