#include <stdio.h>

#define MAX_PRODUCTS 100  // �ִ� ��ǰ �� ����

int main() {
    int productCount;            // ��ǰ�� ����
    int stock[MAX_PRODUCTS];     // �� ��ǰ�� �԰� ����
    int* pStock = stock;         // �����ͷ� �迭 ����

    // 1. ��ǰ�� ���� �Է�
    do {
        printf("��ǰ�� ������ �Է��ϼ��� (1 ~ 100): ");
        scanf("%d", &productCount);
    } while (productCount < 1 || productCount > 100);

    // 3. �� ��ǰ�� �԰� ���� �Է�
    for (int i = 0; i < productCount; i++) {
        printf("��ǰ ID %d�� �԰� ������ �Է��ϼ���: ", i + 1);
        scanf("%d", pStock + i);  // �����͸� ����Ͽ� �迭�� �� �Է�
    }

    // 4. �� ��ǰ�� ���� �Ǹ� ���� �Է� �� ��� ����
    for (int i = 0; i < productCount; i++) {
        int sales;
        printf("��ǰ ID %d�� ���� �Ǹ� ������ �Է��ϼ���: ", i + 1);
        scanf("%d", &sales);
        *(pStock + i) -= sales;  // ����� �Ǹ� ���� ����
    }

    // 5. Ư�� ��ǰ ID�� ��� Ȯ�� �� ��ü ��� ���
    int queryID;
    printf("��� Ȯ���� ��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &queryID);

    if (queryID >= 1 && queryID <= productCount) {
        // �Է��� ID�� �ش��ϴ� ��ǰ ��� ���� ���
        printf("%d\n", *(pStock + (queryID - 1)));
    }
    else {
        printf("��ȿ���� ���� ��ǰ ID�Դϴ�.\n");
        
    }

    // ��� ��ǰ�� ��� ���� ���
    for (int i = 0; i < productCount; i++) {
        printf("%d ", *(pStock + i));
    }
    printf("\n");

    return 0;
}
