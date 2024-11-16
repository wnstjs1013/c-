#include <stdio.h>
int getline(char* line)
{
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n')line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main()
{
	char input[100];
	FILE* fp_src;
	FILE* fp_dest;

	if ((fp = fopen("outline.txt", "r")) == NULL) {
		printf("error...");
		return 0;
	}
	if ((fp = fopen("outline2.txt", "w")) == NULL) {
		printf("error...");
		return 0;
	}
	while(feof(fp_src)){
		fgets(input, 100, fp_src);
		printf("Ãâ ·Â Áß");
		fputs(input, fp_dest);
	}

	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}