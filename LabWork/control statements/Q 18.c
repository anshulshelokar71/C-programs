#include <stdio.h>
#include <math.h>

int main() {
    double v, t, wci;

    // Read wind speed (v) and temperature (t) from the user
    printf("Enter the wind speed (in miles per hour): ");
    scanf("%lf", &v);

    printf("Enter the temperature (in Fahrenheit): ");
    scanf("%lf", &t);

    // Calculate Wind Chill Index based on conditions
    if (v >= 0 && v <= 4) {
        wci = t;
    } else if (v >= 45) {
        wci = 1.6 * t - 55;
    } else {
        wci = 91.4 + (91.4 - t) * (0.0203 * v - 0.304 * sqrt(v) - 0.474);
    }

    // Display the calculated Wind Chill Index
    printf("Wind Chill Index: %.2lf\n", wci);

    return 0;
}
