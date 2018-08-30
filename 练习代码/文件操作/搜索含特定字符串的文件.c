#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[30] = "千山暮雪";//要查找的字符串
	char path[50] = "E:\\编程垃圾\\2\\Debug\\1.txt";
	char cmd[100];
	sprintf(cmd, "find /n \"%s\" \"%s\" ", str, path);
	system(cmd);
	system("pause");
}


/*
用法：FIND [/V] [/C] [/N] [/OFF[LINE]] "string" [[drive:][path]filename[ ...]]
参数：
/V 显示所有未包含指定字符串的行。
/C 仅显示包含字符串的行数。
/N 显示行号。
/I 搜索字符串时忽略大小写。
/OFF[LINE] 不要跳过具有脱机属性集的文件。
"string" 指定要搜索的文字串，
[drive:][path]filename
指定要搜索的文件。
如果没有指定路径，FIND 将搜索键入的或者由另一命令产生的文字。

*/