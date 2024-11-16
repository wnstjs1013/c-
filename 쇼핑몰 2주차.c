#include <stdio.h>

int main() {
    int numProducts;            // ��ǰ ����
    int stock[100];             // ��ǰ�� ��� ����
    int sold[100];              // ��ǰ�� �Ǹ� ����
    int totalStock = 0;         // ��ü ��� ����
    int totalSold = 0;          // �� �Ǹ� ����
    int maxSold = 0, minSold = 100; // �ִ�/�ּ� �Ǹŷ�
    int maxID = -1, minID = -1; // �ִ�/�ּ� �Ǹŷ� ��ǰ ID

    // 1. ��ǰ ���� �Է�
    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%d", &numProducts);

    // 2. ��ǰ�� �԰� ���� �Է�
    printf("��ǰ�� �԰� ������ �Է��ϼ���: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i]; // ��ü ��� �ջ�
    }

    // 3. ��ǰ�� �Ǹ� ���� �Է�
    printf("��ǰ�� �Ǹ� ������ �Է��ϼ���: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &sold[i]);
        totalSold += sold[i];    // �� �Ǹŷ� �ջ�
        stock[i] -= sold[i];     // �Ǹŵ� ��ŭ ��� ����

        // �ִ� �Ǹŷ� ���
        if (sold[i] > maxSold) {
            maxSold = sold[i];
            maxID = i + 1; // ��ǰ ID (1���� ����)
        }

        // �ּ� �Ǹŷ� ���
        if (sold[i] < minSold) {
            minSold = sold[i];
            minID = i + 1;
        }
    }

    // 4. ��� ���
    printf("������: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");

    // �� �Ǹŷ� ��� �� �Ǹ��� ���
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", totalSold, (float)totalSold / totalStock * 100);

    // �ִ� �Ǹŵ� ��ǰ ���
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxID, maxSold);

    // ���� ���� �Ǹŵ� ��ǰ ���
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minID, minSold);

    // ��� ���� ��ǰ ���
    printf("��� ����(2 ����) ��ǰ:\n");
    for (int i = 0; i < numProducts; i++) {
        if (stock[i] <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", i + 1, stock[i]);
        }
    }

    return 0;
}
