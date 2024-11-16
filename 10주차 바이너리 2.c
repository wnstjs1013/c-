#include<stdio.h>

int main()
{
	int array[1000];
	FILE* fp;
	int i = 0;
	fp = fopen("array.bin", "rb");
	if (fp == NULL)return -1;

	fread(array, sizeof(int), 100, fp);

	for (int i = 0; i < 100; i++) printf("%d", array[i]);
	fclose(fp);
	return 0;
}