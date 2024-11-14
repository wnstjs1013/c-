#include <stdio.h>

#define MAX_PRODUCTS 100  // 최대 상품 수 정의

int main() {
    int productCount;            // 상품의 종류
    int stock[MAX_PRODUCTS];     // 각 상품의 입고 수량
    int* pStock = stock;         // 포인터로 배열 접근

    // 1. 상품의 종류 입력
    do {
        printf("상품의 종류를 입력하세요 (1 ~ 100): ");
        scanf("%d", &productCount);
    } while (productCount < 1 || productCount > 100);

    // 3. 각 상품의 입고 수량 입력
    for (int i = 0; i < productCount; i++) {
        printf("상품 ID %d의 입고 수량을 입력하세요: ", i + 1);
        scanf("%d", pStock + i);  // 포인터를 사용하여 배열에 값 입력
    }

    // 4. 각 상품의 당일 판매 수량 입력 및 재고 차감
    for (int i = 0; i < productCount; i++) {
        int sales;
        printf("상품 ID %d의 당일 판매 수량을 입력하세요: ", i + 1);
        scanf("%d", &sales);
        *(pStock + i) -= sales;  // 재고에서 판매 수량 차감
    }

    // 5. 특정 상품 ID의 재고 확인 및 전체 재고 출력
    int queryID;
    printf("재고를 확인할 상품 ID를 입력하세요: ");
    scanf("%d", &queryID);

    if (queryID >= 1 && queryID <= productCount) {
        // 입력한 ID에 해당하는 상품 재고 수량 출력
        printf("%d\n", *(pStock + (queryID - 1)));
    }
    else {
        printf("유효하지 않은 상품 ID입니다.\n");
        
    }

    // 모든 상품의 재고 수량 출력
    for (int i = 0; i < productCount; i++) {
        printf("%d ", *(pStock + i));
    }
    printf("\n");

    return 0;
}
