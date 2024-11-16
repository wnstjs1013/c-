#include<stdio.h>
#include<stdlib.h>

typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu(void) {
	int input;
	printf("메뉴입력(1.구조체 만들기,2.구조체 출력하기):");
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
			printf("프로그램을 종료합니다.\n");
		}
	} while (menu > 0);

	return 0;
}