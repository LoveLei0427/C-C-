#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "E:\\�������\\1\\Debug\\1.txt";
	FILE *fp;
	int num; 
	char docmd[100] = "0";
	fp = fopen(path, "w");//���ļ�д����
	scanf("%d%s", &num, &docmd);
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
	}
	else 
	{
		fprintf(fp, "for /l %%i in(1,1,%d )do %s", num, docmd);
	}
	FILE *fp1;
	fp1 = fopen(path, "r");//��ȡ�ļ�����
	if (fp1 == NULL)
	{
		printf("�ļ���ʧ��");
	}
	else
	{
		fscanf(fp1, "for /l %%i in (1,1,%d )do %s", num, docmd);
		printf("num=%d,docmd=%s", num, docmd);
	}
	system("pause");
}