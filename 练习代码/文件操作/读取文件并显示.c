����һ��
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = { "E:\\�������\\1\\file1.txt" };
	char showcmd[200];
	sprintf(showcmd, "type %s", path);
	system(showcmd);
	system("pause...");
}
��������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{	
	char path[100] = "E:\\�������\\1\\file1.txt";
	FILE *fp;
	fp = fopen(path,"r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
	}
	else
	{
		printf("�ļ��򿪳ɹ��������������:\n");
	}
	char ch;
	do
	{
		ch = fgetc(fp);
		putchar(ch);
	} while (ch != EOF);
	fclose(fp);
	system("pause...");
}
