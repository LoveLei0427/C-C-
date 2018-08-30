//文件输出及检索(按行检索)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp;
	char s[5] = "苦";
	fp = fopen("E:\\编程垃圾\\2\\Debug\\诗词.txt","r");
	if (fp == NULL)
	{
		printf("error");
	}
	char str[200] = { 0 };
	while (fgets(str, 200, fp))
	{
		//puts(str);
		char *p = strstr(str,s);
		if (p == NULL)
		{
			//如果检索的那一句话里没有要求的字符则跳过
		}
		else
		{
			puts(str);//检索到含有目的字符则输出那一行
		}
	}
	system("pause");
}