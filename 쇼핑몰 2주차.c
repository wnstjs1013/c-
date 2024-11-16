#include <stdio.h>

int main() {
    int numProducts;            // 상품 개수
    int stock[100];             // 상품별 재고 수량
    int sold[100];              // 상품별 판매 수량
    int totalStock = 0;         // 전체 재고 수량
    int totalSold = 0;          // 총 판매 수량
    int maxSold = 0, minSold = 100; // 최다/최소 판매량
    int maxID = -1, minID = -1; // 최다/최소 판매량 상품 ID

    // 1. 상품 개수 입력
    printf("상품 개수를 입력하세요: ");
    scanf("%d", &numProducts);

    // 2. 상품별 입고 수량 입력
    printf("상품별 입고 수량을 입력하세요: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i]; // 전체 재고 합산
    }

    // 3. 상품별 판매 수량 입력
    printf("상품별 판매 수량을 입력하세요: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &sold[i]);
        totalSold += sold[i];    // 총 판매량 합산
        stock[i] -= sold[i];     // 판매된 만큼 재고 차감

        // 최다 판매량 계산
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxID = i + 1; // 상품 ID (1부터 시작)
        }

        // 최소 판매량 계산
        if (sold[i] < minSold) {
            minSold = sold[i];
            minID = i + 1;
        }
    }

    // 4. 결과 출력
    printf("재고수량: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    // 총 판매량 출력 및 판매율 계산
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, (float)totalSold / totalStock * 100);

    // 최다 판매된 상품 출력
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxID, maxSold);

    // 가장 적게 판매된 상품 출력
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minID, minSold);

    // 재고 부족 상품 출력
    printf("재고 부족(2 이하) 상품:\n");
    for (int i = 0; i < numProducts; i++) {
        if (stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i]);
        }
    }

    return 0;
}
