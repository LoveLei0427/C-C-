//完整实现 所有满足要求的文件末尾添加 HelloWorld!
 
























简单实现：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[60] = "E:\\编程垃圾\\2\\Debug";
	char outputpath[60] = "E:\\编程垃圾\\2\\Debug\\list.txt";
	char CMD[80];
	//格式化字符串指令，查看所有的txt文件
	sprintf(CMD, "dir /b %s\\*.txt>%s", path, outputpath);
	system(CMD);//执行指令，将文件列表输出到一个文件
	char show[60];
	sprintf(show, "type %s", outputpath);
	system(show);
	system("pause");
}