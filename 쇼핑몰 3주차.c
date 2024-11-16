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
                printf("상품 ID %d의 재고가 부족합니다.\n", products[i].id);
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

    printf("재고 수량: %d\n", totalStock);
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, (totalSold * 100.0) / (totalStock + totalSold));
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxID, maxSold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minID, minSold);

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (products[i].stock == 0) {
            printf("상품 ID %d: 재고 부족\n", products[i].id);
        }
    }
}

int main() {
    Product products[NUM_PRODUCTS];
    int choice;
    initializeProducts(products);

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
