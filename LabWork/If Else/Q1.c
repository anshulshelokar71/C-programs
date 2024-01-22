#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("Maximum: %d\n", num1);
    } else {
        printf("Maximum: %d\n", num2);
    }

    return 0;
}
