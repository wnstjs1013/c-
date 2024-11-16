#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct point {
	int x;
	int y;
}POINT;
POINT makePoint(void) {
	POINT p;
	scanf("%d %d", &p.x, &p.y);
	return p;
}
void makeRandomPoints(POINT p[], int size){
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		p[i].x = rand() % 100;
		p[i].y = rand() % 100;
	}

}
void printPoints(POINT p[], int size) {
	for (int i = 0; i < size; i++)
		printf("point[%d]=x:%d,y:%d\n", i, p[i].x, p[i].y);
	}
void saveFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "wb");
	if (fp == NULL) exit(-1);
	fwrite(p, sizeof(POINT), size, fp);
	fclose(fp);
}
void loadFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "wb");
	if (fp == NULL) exit(-1);
	fread(p, sizeof(POINT), size, fp);
	fclose(fp);
}

int main() 
{
	POINT p[10];
    //makeRandomPoints(p,10);
	loadFile(p, 10);
	printPoints(p, 10);
	//savefile(p,10);
	return 0;
}