#include <stdio.h>

#define MAX_ITEMS 10

struct GroceryItem {
    char name[50];
    int quantity;
    float pricePerUnit;
};

int main() {
    struct GroceryItem items[MAX_ITEMS];
    int itemCount;

    // Read the number of items from the user (up to MAX_ITEMS)
    printf("Enter the number of items (up to %d): ", MAX_ITEMS);
    scanf("%d", &itemCount);

    // Read information for each item
    for (int i = 0; i < itemCount; ++i) {
        printf("\nEnter details for item %d:\n", i + 1);

        // Read item name
        printf("Enter item name: ");
        scanf("%s", items[i].name);

        // Read quantity
        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);

        // Read price per unit
        printf("Enter price per unit: ");
        scanf("%f", &items[i].pricePerUnit);
    }

    // Display the grocery bill
    printf("\n--------------------------------------\n");
    printf("               Grocery Bill             \n");
    printf("--------------------------------------\n");
    printf("  Item            Quantity    Price   \n");
    printf("--------------------------------------\n");

    // Calculate and display the total cost for each item
    float totalCost = 0;
    for (int i = 0; i < itemCount; ++i) {
        float itemTotal = items[i].quantity * items[i].pricePerUnit;
        printf("  %-15s %-10d $%.2f\n", items[i].name, items[i].quantity, itemTotal);
        totalCost += itemTotal;
    }

    // Display the total cost of the groceries
    printf("--------------------------------------\n");
    printf("  Total Cost:                     $%.2f\n", totalCost);

    return 0;
}
