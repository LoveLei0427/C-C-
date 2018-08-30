#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	time_t ts;
	srand((unsigned int)time(&ts));
	int num = rand() % 10;
	printf("执行第%d条指令:",num);
	char str[10][10] = { "calc", 
			     "notepad", 
			     "ipconfig", 
			     "tasklist", 
			     "write", 
			     "color 4f", 
			     "msconfig", 
			     "mstsc", 
			     "mspanit", 
			     "cmd" };
	system(str[num]);