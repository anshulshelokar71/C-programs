#include <stdio.h>

int main() {
    float unitCharges, totalBill, surcharge = 0.20;

    printf("Enter Electricity Unit Charges: ");
    scanf("%f", &unitCharges);

    if (unitCharges <= 50) {
        totalBill = unitCharges * 0.50;
    } else if (unitCharges <= 150) {
        totalBill = 50 * 0.50 + (unitCharges - 50) * 0.75;
    } else if (unitCharges <= 250) {
        totalBill = 50 * 0.50 + 100 * 0.75 + (unitCharges - 150) * 1.20;
    } else {
        totalBill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (unitCharges - 250) * 1.50;
    }

    // Add surcharge
    totalBill += totalBill * surcharge;

    // Display total electricity bill
    printf("Total Electricity Bill: Rs. %.2f\n", totalBill);

    return 0;
}
