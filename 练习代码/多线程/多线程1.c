#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
void print(void *p)
{
	
	Sleep(1000);
	printf("HelloWorld! ");
	return;
}
void time(void *p)
{
	int i=0;
	char str[100] = { 0 };
	while (1)
	{
		char str[100] = { 0 };
		sprintf(str, "title ��ʱ�ǵ�%d��", i);
		system(str);
		i++;
		Sleep(1000);
	}
}
void main()
{
	/*
	��ʱ���̼���ʵ��print����ͬʱʵ��time	
	*/
	_beginthread(time, 0, NULL);
	uintptr_t hd;   //uintptr��һ�ָ߼�int����
	for (int i = 0; i < 5; i++)
	{
	    hd = _beginthread(print, 0, NULL);
		Sleep(2000);
	}		
	printf("%d", hd);
	system("pause");
}