#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILE_NAME "products.txt"

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

void saveProductsToFile() {
    FILE* file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("파일 저장 실패!\n");
        return;
    }
    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", products[i].id, products[i].name, products[i].price,
            products[i].stock_in, products[i].stock_out, products[i].total_stock);
    }
    fclose(file);
    printf("상품 정보가 저장되었습니다.\n");
}

void loadProductsFromFile() {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("저장된 파일이 없습니다.\n");
        return;
    }
    product_count = 0;
    while (fscanf(file, "%d %s %d %d %d %d", &products[product_count].id, products[product_count].name,
        &products[product_count].price, &products[product_count].stock_in,
        &products[product_count].stock_out, &products[product_count].total_stock) != EOF) {
        product_count++;
    }
    fclose(file);
    printf("상품 정보가 불러와졌습니다.\n");
}

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
    loadProductsFromFile();

    while (1) {
        printf("\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 저장, 6. 종료): ");
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
            saveProductsToFile();
            break;
        case 6:
            printf("프로그램을 종료합니다.\n");
            saveProductsToFile();
            return 0;
        default:
            printf("올바른 번호를 입력하세요.\n");
        }
    }
    return 0;
}
