#include <stdio.h>

#define MAX_PRODUCTS 5

// ��ǰ ����ü
typedef struct {
    char name[50];
    int stock;
} Product;

Product products[MAX_PRODUCTS];  // ��ǰ �迭

// �޴� ��� �Լ�
void showMenu() {
    printf("1. �԰�\n2. �Ǹ�\n3. ���Ȯ��\n4. ��ǰ�� �Է�\n5. ����\n");
}

// ��ǰ�� �Է� �Լ�
void inputProductNames() {
    printf("��ǰ���� �Է��ϼ���:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("��ǰ %d �̸�: ", i + 1);
        scanf("%s", products[i].name);
        products[i].stock = 0;  // �ʱ� ��� 0���� ����
    }
}

// �԰� �Լ�
void addStock() {
    int id, quantity;
    printf("�԰��� ��ǰ ��ȣ�� ������ �Է��ϼ��� (��: 1 10): ");
    scanf("%d %d", &id, &quantity);
    products[id - 1].stock += quantity;
    printf("%s�� ��� %d�� �߰��Ǿ����ϴ�.\n", products[id - 1].name, quantity);
}

// �Ǹ� �Լ�
void sellProduct() {
    int id, quantity;
    printf("�Ǹ��� ��ǰ ��ȣ�� ������ �Է��ϼ��� (��: 1 5): ");
    scanf("%d %d", &id, &quantity);

    if (products[id - 1].stock >= quantity) {
        products[id - 1].stock -= quantity;
        printf("%s�� %d���� �ǸŵǾ����ϴ�.\n", products[id - 1].name, quantity);
    }
    else {
        printf("��� �����մϴ�.\n");
    }
}

// ��� Ȯ�� �Լ�
void showStock() {
    printf("�����Ȳ:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s: %d��\n", products[i].name, products[i].stock);
    }
}

int main() {
    int choice;
    inputProductNames();  // ó���� ��ǰ���� �Է¹���

    while (1) {
        showMenu();  // �޴��� ���
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStock();  // �԰�
            break;
        case 2:
            sellProduct();  // �Ǹ�
            break;
        case 3:
            showStock();  // ��� Ȯ��
            break;
        case 4:
            inputProductNames();  // ��ǰ�� �ٽ� �Է�
            break;
        case 5:
            printf("���α׷� ����\n");
            return 0;  // ���α׷� ����
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    return 0;
}
