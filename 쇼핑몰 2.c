#include <stdio.h>

#define MAX_PRODUCTS 100

int main() {
    int numProducts;
    int stock[MAX_PRODUCTS], sales[MAX_PRODUCTS];
    int id;

   
    printf("Enter the number of products (1 to 100): ");
    scanf("%d", &numProducts);

    if (numProducts < 1 || numProducts > 100) {
        printf("Invalid number of products.\n");
        return 1;
    }

    
    printf("Enter the inventory quantities for each product: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &stock[i]);
    }

    
    printf("Enter the sales quantities for each product: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &sales[i]);
    }

    
    printf("Enter the ID of the product to check inventory: ");
    scanf("%d", &id);

    if (id < 1 || id > numProducts) {
        printf("Invalid product ID.\n");
        return 1;
    }

    int productIndex = id - 1;
    int remainingStock = stock[productIndex] - sales[productIndex];
    printf("Inventory for product ID %d: %d\n", id, remainingStock);

   
    printf("All inventory quantities:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", stock[i] - sales[i]);
    }
    printf("\n");

   
    int totalSales = 0;
    for (int i = 0; i < numProducts; i++) {
        totalSales += sales[i];
    }
    printf("Total sales quantity: %d\n", totalSales);

    
    int maxSales = sales[0], minSales = sales[0];
    int maxID = 1, minID = 1;

    for (int i = 1; i < numProducts; i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxID = i + 1;
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minID = i + 1;
        }
    }
    printf("Maximum sales: Product ID %d with %d units sold\n", maxID, maxSales);
    printf("Minimum sales: Product ID %d with %d units sold\n", minID, minSales);

    printf("Reorder Warning:\n");
    for (int i = 0; i < numProducts; i++) {
        if (stock[i] - sales[i] <= 2) {
            printf("Product ID %d is low on stock: %d left\n", i + 1, stock[i] - sales[i]);
        }
    }

    return 0;
}

