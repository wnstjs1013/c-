#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

typedef struct {
    int id;
    char name[50];
    int price;
    int stock_in;
    int stock_out;
    int total_stock;
} Product;

Product products[MAX_PRODUCTS];
int product_count = 0;

void addOrUpdateProduct() {
    int id, stock_in;
    char name[50];
    int price;

    printf("상품 ID 입력: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("입고 수량 입력: ");
        scanf("%d", &stock_in);
        products[found].total_stock += stock_in;
        printf("상품 업데이트 완료!\n");
    }
    else {
        if (product_count < MAX_PRODUCTS) {
            printf("상품명 입력: ");
            scanf("%s", name);
            printf("상품 가격 입력: ");
            scanf("%d", &price);
            printf("입고 수량 입력: ");
            scanf("%d", &stock_in);

            products[product_count].id = id;
            strcpy(products[product_count].name, name);
            products[product_count].price = price;
            products[product_count].stock_in = stock_in;
            products[product_count].stock_out = 0;
            products[product_count].total_stock = stock_in;

            product_count++;
            printf("새로운 상품 추가 완료!\n");
        }
        else {
            printf("상품 개수를 초과했습니다.\n");
        }
    }
}

void sellProduct() {
    int id, sell_qty;

    printf("판매 상품 ID 입력: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("판매 수량 입력: ");
        scanf("%d", &sell_qty);
        if (products[found].total_stock >= sell_qty) {
            products[found].total_stock -= sell_qty;
            products[found].stock_out += sell_qty;
            printf("판매 완료!\n");
        }
        else {
            printf("재고가 부족합니다.\n");
        }
    }
    else {
        printf("해당 상품이 없습니다.\n");
    }
}

void showProductStatus() {
    int id;
    printf("상품 ID 입력: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("상품명: %s, 가격: %d, 총 재고: %d, 판매량: %d\n",
            products[found].name, products[found].price,
            products[found].total_stock, products[found].stock_out);
    }
    else {
        printf("해당 상품이 없습니다.\n");
    }
}

void showAllProducts() {
    printf("전체 상품 현황:\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, 상품명: %s, 가격: %d, 총 재고: %d, 판매량: %d\n",
            products[i].id, products[i].name, products[i].price,
            products[i].total_stock, products[i].stock_out);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addOrUpdateProduct();
            break;
        case 2:
            sellProduct();
            break;
        case 3:
            showProductStatus();
            break;
        case 4:
            showAllProducts();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("올바른 번호를 입력하세요.\n");
        }
    }
    return 0;
}
