#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
void print(void *p)
{
	int i = 0;
	/*
	此线程从11秒开始没一秒结束一个线程知道15秒为止
	*/
	while(1)
	{
		if (i > 10)
		{
			printf("%d\n", i);
			_endthread(); 
			/*
			结束当前线程,也可用return替代（线程执行完毕后进行返回)
			*/
		}
		Sleep(1000);
		i++;
	}
	//
}
void time(void *p)
{
	int i=0;
	char str[100] = { 0 };
	while (1)
	{
		char str[100] = { 0 };
		sprintf(str, "title 此时是第%d秒", i);
		system(str);
		i++;
		Sleep(1000);
	}
}
void main()
{
	_beginthread(time, 0, NULL);
	uintptr_t hd;   //uintptr是一种高级int类型
	for (int i = 0; i < 5; i++)
	{
	    hd = _beginthread(print, 0, NULL);
		Sleep(2000);
	}			
	system("pause");
}