#include <stdio.h>

#define MAX_PRODUCTS 100 // �ִ� ��ǰ ����

int main() {
    int numProducts; // ��ǰ ����(����)
    int stock[MAX_PRODUCTS] = { 0 }; // ��ǰ�� ���
    int sales[MAX_PRODUCTS] = { 0 }; // ��ǰ�� �Ǹŷ�
    int totalStock = 0; // ��ü ���
    int id; // ��ǰ ID �Է�

    // 1. ��ǰ ���� �Է�
    printf("��ǰ ����(1~100)�� �Է��ϼ���: ");
    scanf("%d", &numProducts);
    if (numProducts < 1 || numProducts > MAX_PRODUCTS) {
        printf("�߸��� ��ǰ �����Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    // 2. ��ǰ�� �԰� ���� �Է�
    printf("��ǰ�� �԰� ������ �Է��ϼ���(%d��): ", numProducts);
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i]; // ��ü ��� ���
    }

    // 3. ��ǰ�� �Ǹ� ���� �Է�
    printf("��ǰ�� �Ǹ� ������ �Է��ϼ���(%d��): ", numProducts);
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &sales[i]);
        stock[i] -= sales[i]; // �Ǹŵ� ��ŭ ��� ����
        if (stock[i] < 0) stock[i] = 0; // ���� ������ �� �� ����
    }

    // 4. Ư�� ��ǰ ID �Է� �� ��� ���
    printf("Ȯ���� ��ǰ ID�� �Է��ϼ���(1~%d): ", numProducts);
    scanf("%d", &id);
    if (id >= 1 && id <= numProducts) {
        printf("��ǰ ID %d�� ��� ����: %d\n", id, stock[id - 1]);
    }
    else {
        printf("�߸��� ��ǰ ID�Դϴ�.\n");
    }

    // 5. ��ü ��ǰ�� ��� ���
    printf("��ü ��ǰ�� ��� ����: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    return 0;
}
