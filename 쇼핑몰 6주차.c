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
        printf("���� ���� ����!\n");
        return;
    }
    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", products[i].id, products[i].name, products[i].price,
            products[i].stock_in, products[i].stock_out, products[i].total_stock);
    }
    fclose(file);
    printf("��ǰ ������ ����Ǿ����ϴ�.\n");
}

void loadProductsFromFile() {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("����� ������ �����ϴ�.\n");
        return;
    }
    product_count = 0;
    while (fscanf(file, "%d %s %d %d %d %d", &products[product_count].id, products[product_count].name,
        &products[product_count].price, &products[product_count].stock_in,
        &products[product_count].stock_out, &products[product_count].total_stock) != EOF) {
        product_count++;
    }
    fclose(file);
    printf("��ǰ ������ �ҷ��������ϴ�.\n");
}

void addOrUpdateProduct() {
    int id, stock_in;
    char name[50];
    int price;

    printf("��ǰ ID �Է�: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("�԰� ���� �Է�: ");
        scanf("%d", &stock_in);
        products[found].total_stock += stock_in;
        printf("��ǰ ������Ʈ �Ϸ�!\n");
    }
    else {
        if (product_count < MAX_PRODUCTS) {
            printf("��ǰ�� �Է�: ");
            scanf("%s", name);
            printf("��ǰ ���� �Է�: ");
            scanf("%d", &price);
            printf("�԰� ���� �Է�: ");
            scanf("%d", &stock_in);

            products[product_count].id = id;
            strcpy(products[product_count].name, name);
            products[product_count].price = price;
            products[product_count].stock_in = stock_in;
            products[product_count].stock_out = 0;
            products[product_count].total_stock = stock_in;

            product_count++;
            printf("���ο� ��ǰ �߰� �Ϸ�!\n");
        }
        else {
            printf("��ǰ ������ �ʰ��߽��ϴ�.\n");
        }
    }
}

void sellProduct() {
    int id, sell_qty;

    printf("�Ǹ� ��ǰ ID �Է�: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("�Ǹ� ���� �Է�: ");
        scanf("%d", &sell_qty);
        if (products[found].total_stock >= sell_qty) {
            products[found].total_stock -= sell_qty;
            products[found].stock_out += sell_qty;
            printf("�Ǹ� �Ϸ�!\n");
        }
        else {
            printf("��� �����մϴ�.\n");
        }
    }
    else {
        printf("�ش� ��ǰ�� �����ϴ�.\n");
    }
}

void showProductStatus() {
    int id;
    printf("��ǰ ID �Է�: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("��ǰ��: %s, ����: %d, �� ���: %d, �Ǹŷ�: %d\n",
            products[found].name, products[found].price,
            products[found].total_stock, products[found].stock_out);
    }
    else {
        printf("�ش� ��ǰ�� �����ϴ�.\n");
    }
}

void showAllProducts() {
    printf("��ü ��ǰ ��Ȳ:\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, ��ǰ��: %s, ����: %d, �� ���: %d, �Ǹŷ�: %d\n",
            products[i].id, products[i].name, products[i].price,
            products[i].total_stock, products[i].stock_out);
    }
}

int main() {
    int choice;
    loadProductsFromFile();

    while (1) {
        printf("\n���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ����, 6. ����): ");
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
            printf("���α׷��� �����մϴ�.\n");
            saveProductsToFile();
            return 0;
        default:
            printf("�ùٸ� ��ȣ�� �Է��ϼ���.\n");
        }
    }
    return 0;
}
