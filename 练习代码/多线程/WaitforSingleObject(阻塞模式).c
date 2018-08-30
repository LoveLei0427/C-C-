#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
void print(void *p)
{
	int *px =(int *) p;

	int i = 0;
	/*
	此线程从11秒开始没一秒结束一个线程知道15秒为止
	*/
	while(1)
	{
		//每大于5S时就执行一个线程
		if (i > 5)
		{
			printf("%d	%d\n", i,*px);
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
	    HANDLE hd = _beginthread(print, 0, &i);
		//WaitforSingleObject为依次执行模式，非并行
		WaitForSingleObject(hd, INFINITE);//INFINITE为无限期等待
	}			
	system("pause");
}