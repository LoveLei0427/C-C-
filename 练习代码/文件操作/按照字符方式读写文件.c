//读写文件内容并显示到控制台下
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	fp = fopen("E:\\编程垃圾\\2\\Debug\\诗词.txt","r");
	if (fp == NULL)
	{
		perror("the false of the file is:");
	}
	else
	{
		while (!feof(fp))
		{			//若fp已经指向文件末尾,则feof(fp)函数值为						//“真”,即返回非零值;否则返回0。
			char ch = getc(fp);
			putchar(ch);
		}
	}
	fclose(fp);
	system("pause");
}