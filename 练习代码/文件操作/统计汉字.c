GBK规定，汉字，日文，韩文，或中文标点等第一个字节大于128

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char path[100] = "E:\\编程垃圾\\2\\Debug\\1.txt";
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("the false of file is:");//输出错误类型
	}
	int x;//fhetcde返回值是int类型，int占四个字节来存储汉字编码，不可以用char
	int hanzi = 0;
	while ((x = fgetc(fp))!=EOF)
	{
		if (x > 128)
		{
			x = fgetc(fp);//汉子占两个字节，再往前读一个字节
			hanzi++;
		}
	}
	printf("hanzi=%d", hanzi);
	fclose(fp);
	system("pause...");
}

/*
有时候只是单纯判断汉字的个数忽略汉字标点那么if语句可改为
{
	int a = fgetc(fp);
		if()
		  {
			...
		   }	
}
*/