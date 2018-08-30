#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "C:\\Users\\Administrator\\Desktop";//源文件路径
	char filename[300] = "*.*";//要搜索的文件名及类型
	char out[100] = "C:\\Users\\Administrator\\Desktop\\out.txt";//目的文件路径及文件
	char cmd[512];
	sprintf(cmd, "for /r \"%s\" %%i in (%s) do @echo %%i", path, filename,out);
	system(cmd);//执行文件
	char show[100];
	sprintf(show, "type %s", out);
	system(show);//显示目的文件内容
	system("pause...");
}