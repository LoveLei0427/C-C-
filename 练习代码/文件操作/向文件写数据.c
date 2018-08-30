//向文件写入数据：

1. 调用Echo批处理
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100] = "i love u";
	char des[100] = "E:\\编程垃圾\\2\\Debug\\6.txt";
	char cmd[100];
	sprintf(cmd, "echo %s>>%s", str, des); // ">>"追加写入到文件中, ">"覆盖写入
	system(cmd);       
	system("pause");
}

2.文件方式实现
	FILE *fp;
	fp =fopen("E:\\编程垃圾\\2\\Debug\\6.txt","w");
	if (fp == NULL)
	{
		printf("error");
	}
	else
	{
		char str[100] = "i love u";
		int length = strlen(str);
		for (int i = 0; i<length; i++)//获取字符长度，一个字符一个字符写入
		{
			fputc(str[i],fp);
		}
	}
	fclose(fp);

3.由命令窗口向文件写入 Ctrl+Z结束
		char ch = getchar();
		while (ch!=EOF)
		{
			fputc(ch, fp);
			ch = getchar();
		}
	
