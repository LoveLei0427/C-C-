#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fpr;
	FILE *fpw;
	fpr = fopen("E:\\±à³ÌÀ¬»ø\\2\\Debug\\Ê«´Ê.txt","r");
	fpw = fopen("E:\\±à³ÌÀ¬»ø\\2\\Debug\\Ê«´Ê1.txt", "w");
	if (fpr == NULL)
	{
		perror("the false of the file is:");
		return;
	}
	if (fpr == NULL)
	{
		perror("the false of the file is:");
		return;
	}
	else
	{
		while (!feof(fpr))
		{
			char ch = getc(fpr);
			putchar(ch);
			fputc(ch, fpw);
		}
	}
	printf("\n");
	fclose(fpr);
	fclose(fpw);
	system("pause");
}



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fpr;
	FILE *fpw;
	//char s[5] = "¿à";
	fpr = fopen("E:\\±à³ÌÀ¬»ø\\2\\Debug\\Ê«´Ê.txt","r");
	fpw = fopen("E:\\±à³ÌÀ¬»ø\\2\\Debug\\Ê«´Ê3.txt", "w");
	if (fpr == NULL)
	{
		printf("error");
	}
	char str[200] = { 0 };
	while (fgets(str, 200, fpr))
	{
		puts(str);
		fputs(str, fpw);
	}
	system("pause");
}