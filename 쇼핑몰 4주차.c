#include <stdio.h>
#include <limits.h>

#define NUM_PRODUCTS 5

typedef struct {
    int stock;
    int sold;
} Product;

void inputStock(Product products[]) {
    int option;
    printf("입고 방법 선택 (1: 전체, 2: 개별): ");
    scanf("%d", &option);

    if (option == 1) {
        printf("전체 상품 입고 수량 입력: ");
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            scanf("%d", &products[i].stock);
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("상품 ID와 입고 수량 입력: ");
        scanf("%d %d", &id, &quantity);
        if (id >= 1 && id <= NUM_PRODUCTS) {
            products[id - 1].stock += quantity;
        }
        else {
            printf("잘못된 상품 ID입니다.\n");
        }
    }
}

void sellProduct(Product products[]) {
    int option;
    printf("판매 방법 선택 (1: 전체, 2: 개별): ");
    scanf("%d", &option);

    if (option == 1) {
        printf("전체 상품 판매 수량 입력: ");
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            int quantity;
            scanf("%d", &quantity);
            if (quantity <= products[i].stock) {
                products[i].stock -= quantity;
                products[i].sold += quantity;
            }
            else {
                printf("상품 %d의 재고가 부족합니다.\n", i + 1);
            }
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("상품 ID와 판매 수량 입력: ");
        scanf("%d %d", &id, &quantity);
        if (id >= 1 && id <= NUM_PRODUCTS) {
            if (quantity <= products[id - 1].stock) {
                products[id - 1].stock -= quantity;
                products[id - 1].sold += quantity;
            }
            else {
                printf("해당 상품의 재고가 부족합니다.\n");
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

    printf("재고 수량: %d%d%d%d%d\n", products[0].stock, products[1].stock, products[2].stock, products[3].stock, products[4].stock);
    printf("총 판매량: %d\n", totalSold);
}

int main() {
    Product products[NUM_PRODUCTS] = { 0 };
    int choice;

    while (1) {
        printf("\n메뉴 선택 (1: 입고, 2: 판매, 3: 현황, 4: 종료): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: inputStock(products); break;
        case 2: sellProduct(products); break;
        case 3: displayInventoryStatus(products); break;
        case 4: printf("프로그램을 종료합니다.\n"); return 0;
        default: printf("잘못된 선택입니다.\n");
        }
    }
}
