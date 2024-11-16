#include <stdio.h>
#include <limits.h>  // Include limits.h to use INT_MAX

#define NUM_PRODUCTS 5

typedef struct {
    int id;
    int stock;
    int sold;
} Product;

void initializeProducts(Product products[]) {
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        products[i].id = i + 1;
        products[i].stock = 0;
        products[i].sold = 0;
    }
}

void inputStock(Product products[]) {
    int option;
    printf("�԰� ��� ���� (1: ��ü, 2: ����): ");
    scanf("%d", &option);

    if (option == 1) {
        printf("��ü ��ǰ �԰� ���� �Է�: ");
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            scanf("%d", &products[i].stock);
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("��ǰ ID�� �԰� ���� �Է�: ");
        scanf("%d %d", &id, &quantity);
        if (id >= 1 && id <= NUM_PRODUCTS) {
            products[id - 1].stock += quantity;
        }
        else {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
        }
    }
}

void sellProduct(Product products[]) {
    int option;
    printf("�Ǹ� ��� ���� (1: ��ü, 2: ����): ");
    scanf("%d", &option);

    if (option == 1) {
        printf("��ü ��ǰ �Ǹ� ���� �Է�: ");
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            int quantity;
            scanf("%d", &quantity);
            if (quantity <= products[i].stock) {
                products[i].stock -= quantity;
                products[i].sold += quantity;
            }
            else {
                printf("��ǰ ID %d�� ��� �����մϴ�.\n", products[i].id);
            }
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("��ǰ ID�� �Ǹ� ���� �Է�: ");
        scanf("%d %d", &id, &quantity);
        if (id >= 1 && id <= NUM_PRODUCTS) {
            if (quantity <= products[id - 1].stock) {
                products[id - 1].stock -= quantity;
                products[id - 1].sold += quantity;
            }
            else {
                printf("�ش� ��ǰ�� ��� �����մϴ�.\n");
            }
        }
    }
}

void displayInventoryStatus(Product products[]) {
    int totalStock = 0, totalSold = 0, maxSold = 0, minSold = INT_MAX;
    int maxID = 0, minID = 0;

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        totalStock += products[i].stock;
        totalSold += products[i].sold;
        if (products[i].sold > maxSold) {
            maxSold = products[i].sold;
            maxID = products[i].id;
        }
        if (products[i].sold < minSold) {
            minSold = products[i].sold;
            minID = products[i].id;
        }
    }

    printf("��� ����: %d\n", totalStock);
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", totalSold, (totalSold * 100.0) / (totalStock + totalSold));
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxID, maxSold);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minID, minSold);

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (products[i].stock == 0) {
            printf("��ǰ ID %d: ��� ����\n", products[i].id);
        }
    }
}

int main() {
    Product products[NUM_PRODUCTS];
    int choice;
    initializeProducts(products);

    while (1) {
        printf("\n�޴� ���� (1: �԰�, 2: �Ǹ�, 3: ��Ȳ, 4: ����): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: inputStock(products); break;
        case 2: sellProduct(products); break;
        case 3: displayInventoryStatus(products); break;
        case 4: printf("���α׷��� �����մϴ�.\n"); return 0;
        default: printf("�߸��� �����Դϴ�.\n");
        }
    }
}
