#include <stdio.h>

int main() {

    int angle1, angle2, angle3;

    printf("Enter three angles of the triangle: ");
    scanf("%d %d %d", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 == 180 && angle1 > 0 && angle2 > 0 && angle3 > 0) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}
