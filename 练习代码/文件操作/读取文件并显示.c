方法一：
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = { "E:\\编程垃圾\\1\\file1.txt" };
	char showcmd[200];
	sprintf(showcmd, "type %s", path);
	system(showcmd);
	system("pause...");
}
方法二：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{	
	char path[100] = "E:\\编程垃圾\\1\\file1.txt";
	FILE *fp;
	fp = fopen(path,"r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
	}
	else
	{
		printf("文件打开成功，里面的内容是:\n");
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
