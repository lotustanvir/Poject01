#include <stdio.h>
#include <string.h>

// Define the structure for product details
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product
void addProduct(struct Product inventory[], int *count) { //pointer one time call.
    if (*count >= 100) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", &inventory[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*count].price);

    (*count)++; // count=1
    printf("Product added successfully!\n");
}

// Function to display all products
void displayProducts(struct Product inventory[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nInventory Details:\n");
    printf("-------------------------------------------------\n");
    printf("Name\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------\n");// what is \t?
}

// Function to check stock levels
void checkStock(struct Product inventory[], int count) {
    char productName[50];
    printf("Enter the product name to check stock: ");
    scanf("%s", productName);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {  //strcmp?
            if (inventory[i].quantity == 0) {
                printf("Product '%s' is out of stock.\n", productName);
            } else {
                printf("Product '%s' has %d units in stock.\n", productName, inventory[i].quantity);
            }
            return;
        }
    }

    printf("Product '%s' not found in inventory.\n", productName);
}

// Main function
int main() {
    struct Product inventory[100]; // Array to store up to 100 products
    int count = 0; // Counter for the number of products
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Check Stock Level\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                checkStock(inventory, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}