#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//创建临时文件、tmpfile具备二进制读写权限 
//关闭文件或程序后就自动删除
//对临时文件修改为.txt格式
void main()
{
	FILE *tmpfile;//创建文件指针
	char path[100];//创建路径，保存临时文件名
	tmpnam(path);//产生一个唯一的文件名保存到path
	char *p = path;   //修改文件为.txt格式
	while (*p != '\0')
	{
		if (*p == '.')
		{
			*p = '0';
		}
		p++;
	}
	strcat(path, ".txt");
	printf("文件路径是%s", path);
	tmpfile = fopen(path, "w+");//按照可读可写的方式打开
	if (tmpfile == NULL)
	{
		perror("the false of file is:");
	}
	fputs("渺万里层云，千山暮雪，只影向谁去？", tmpfile);
	rewind(tmpfile);
	char str[512];
	fgets(str, 512, tmpfile);
	fclose(tmpfile);
	system("pause...");
}