#include<stdio.h>
#include<stdlib.h>

typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu(void) {
	int input;
	printf("�޴��Է�(1.����ü �����,2.����ü ����ϱ�):");
	scanf("%d", &input);
	return input;
}
int main() {
	int menu;

	do {
		menu = inputMenu();
		if (menu == 1) {
		}
		else if (menu == 2) {
		
		}
		else if (menu == -1) {
			printf("���α׷��� �����մϴ�.\n");
		}
	} while (menu > 0);

	return 0;
}