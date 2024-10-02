#include <stdio.h>

#define MAX_PRODUCTS 5

// 제품 구조체
typedef struct {
    char name[50];
    int stock;
} Product;

Product products[MAX_PRODUCTS];  // 제품 배열

// 메뉴 출력 함수
void showMenu() {
    printf("1. 입고\n2. 판매\n3. 재고확인\n4. 상품명 입력\n5. 종료\n");
}

// 상품명 입력 함수
void inputProductNames() {
    printf("상품명을 입력하세요:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("상품 %d 이름: ", i + 1);
        scanf("%s", products[i].name);
        products[i].stock = 0;  // 초기 재고를 0으로 설정
    }
}

// 입고 함수
void addStock() {
    int id, quantity;
    printf("입고할 상품 번호와 수량을 입력하세요 (예: 1 10): ");
    scanf("%d %d", &id, &quantity);
    products[id - 1].stock += quantity;
    printf("%s의 재고가 %d개 추가되었습니다.\n", products[id - 1].name, quantity);
}

// 판매 함수
void sellProduct() {
    int id, quantity;
    printf("판매할 상품 번호와 수량을 입력하세요 (예: 1 5): ");
    scanf("%d %d", &id, &quantity);

    if (products[id - 1].stock >= quantity) {
        products[id - 1].stock -= quantity;
        printf("%s의 %d개가 판매되었습니다.\n", products[id - 1].name, quantity);
    }
    else {
        printf("재고가 부족합니다.\n");
    }
}

// 재고 확인 함수
void showStock() {
    printf("재고현황:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s: %d개\n", products[i].name, products[i].stock);
    }
}

int main() {
    int choice;
    inputProductNames();  // 처음에 상품명을 입력받음

    while (1) {
        showMenu();  // 메뉴를 출력
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStock();  // 입고
            break;
        case 2:
            sellProduct();  // 판매
            break;
        case 3:
            showStock();  // 재고 확인
            break;
        case 4:
            inputProductNames();  // 상품명 다시 입력
            break;
        case 5:
            printf("프로그램 종료\n");
            return 0;  // 프로그램 종료
        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
