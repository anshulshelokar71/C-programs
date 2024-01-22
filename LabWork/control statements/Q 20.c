#include <stdio.h>

int main() {
    // Variables to store user input
    char item[100];
    double price;
    int overnightDelivery;

    // Get user input
    printf("Enter the item: ");
    scanf("%s", item);

    printf("Enter the price: ");
    scanf("%lf", &price);

    printf("Overnight delivery (0==no, 1==yes): ");
    scanf("%d", &overnightDelivery);

    // Calculate shipping cost based on item price
    double shippingCost;
    if (price < 100.0) {
        shippingCost = 20.0;
    } else {
        shippingCost = 30.0;
    }

    // Add additional cost for overnight delivery
    if (overnightDelivery == 1) {
        shippingCost += 50.0;
    }

    // Calculate total cost
    double totalCost = price + shippingCost;

    // Display the invoice
    printf("Invoice: %s Rs.%.2f shipping Rs.%.2f total Rs. %.2f\n", item, price, shippingCost, totalCost);

    return 0;
}
