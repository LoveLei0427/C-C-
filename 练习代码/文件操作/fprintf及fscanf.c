#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "E:\\编程垃圾\\1\\Debug\\1.txt";
	FILE *fp;
	int num; 
	char docmd[100] = "0";
	fp = fopen(path, "w");//向文件写数据
	scanf("%d%s", &num, &docmd);
	if (fp == NULL)
	{
		printf("文件打开失败");
	}
	else 
	{
		fprintf(fp, "for /l %%i in(1,1,%d )do %s", num, docmd);
	}
	FILE *fp1;
	fp1 = fopen(path, "r");//读取文件内容
	if (fp1 == NULL)
	{
		printf("文件打开失败");
	}
	else
	{
		fscanf(fp1, "for /l %%i in (1,1,%d )do %s", num, docmd);
		printf("num=%d,docmd=%s", num, docmd);
	}
	system("pause");
}