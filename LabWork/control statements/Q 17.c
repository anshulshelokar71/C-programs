#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum = num;
    int n = 0, sum = 0;

    // Count the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num; // Reset originalNum to the input value

    // Calculate the sum of nth powers of digits
    while (originalNum != 0) {
        int digit = originalNum % 10;
        sum += pow(digit, n);
        originalNum /= 10;
    }

    // Check if the number is an Armstrong number
    return (sum == num);
}

int main() {
    int number;

    do {
        // Read a number from the user
        printf("Enter a number (-1 to exit): ");
        scanf("%d", &number);

        // Check if the number is -1
        if (number == -1) {
            break;  // Exit the loop if -1 is entered
        }

        // Check if the number is an Armstrong number
        if (isArmstrong(number)) {
            printf("%d is an Armstrong number.\n", number);
        } else {
            printf("%d is not an Armstrong number.\n", number);
        }

    } while (1);  // Infinite loop until -1 is entered

    printf("Program exited. Goodbye!\n");

    return 0;
}
