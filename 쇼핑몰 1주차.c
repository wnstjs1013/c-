#include <stdio.h>

#define MAX_PRODUCTS 100 // 최대 상품 개수

int main() {
    int numProducts; // 상품 종류(개수)
    int stock[MAX_PRODUCTS] = { 0 }; // 상품별 재고
    int sales[MAX_PRODUCTS] = { 0 }; // 상품별 판매량
    int totalStock = 0; // 전체 재고
    int id; // 상품 ID 입력

    // 1. 상품 종류 입력
    printf("상품 종류(1~100)를 입력하세요: ");
    scanf("%d", &numProducts);
    if (numProducts < 1 || numProducts > MAX_PRODUCTS) {
        printf("잘못된 상품 종류입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    // 2. 상품별 입고 수량 입력
    printf("상품별 입고 수량을 입력하세요(%d개): ", numProducts);
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i]; // 전체 재고 계산
    }

    // 3. 상품별 판매 수량 입력
    printf("상품별 판매 수량을 입력하세요(%d개): ", numProducts);
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &sales[i]);
        stock[i] -= sales[i]; // 판매된 만큼 재고 감소
        if (stock[i] < 0) stock[i] = 0; // 재고는 음수가 될 수 없음
    }

    // 4. 특정 상품 ID 입력 및 재고 출력
    printf("확인할 상품 ID를 입력하세요(1~%d): ", numProducts);
    scanf("%d", &id);
    if (id >= 1 && id <= numProducts) {
        printf("상품 ID %d의 재고 수량: %d\n", id, stock[id - 1]);
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }

    // 5. 전체 상품의 재고 출력
    printf("전체 상품의 재고 수량: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    return 0;
}
