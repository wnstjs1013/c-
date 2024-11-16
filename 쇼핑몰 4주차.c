#include <stdio.h>
#include <limits.h>

#define NUM_PRODUCTS 5

typedef struct {
    int stock;
    int sold;
} Product;

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
                printf("��ǰ %d�� ��� �����մϴ�.\n", i + 1);
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
    int totalStock = 0, totalSold = 0;
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        totalStock += products[i].stock;
        totalSold += products[i].sold;
    }

    printf("��� ����: %d%d%d%d%d\n", products[0].stock, products[1].stock, products[2].stock, products[3].stock, products[4].stock);
    printf("�� �Ǹŷ�: %d\n", totalSold);
}

int main() {
    Product products[NUM_PRODUCTS] = { 0 };
    int choice;

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
