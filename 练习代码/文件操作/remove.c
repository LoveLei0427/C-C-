#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<io.h>
//#include<string.h>
void main()
{
	char path[100] = "C:\\Users\\Administrator\\Desktop\\XXXXXX";
	char *newname = _mktemp(path);
	printf("%s\n%s\n", newname, path);
	char cmd[100];
	sprintf(cmd, "md %s", path);
	system(cmd);
	system("pause...");
}