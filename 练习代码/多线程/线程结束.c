#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
void print(void *p)
{
	int i = 0;
	/*
	���̴߳�11�뿪ʼûһ�����һ���߳�֪��15��Ϊֹ
	*/
	while(1)
	{
		if (i > 10)
		{
			printf("%d\n", i);
			_endthread(); 
			/*
			������ǰ�߳�,Ҳ����return������߳�ִ����Ϻ���з���)
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
		sprintf(str, "title ��ʱ�ǵ�%d��", i);
		system(str);
		i++;
		Sleep(1000);
	}
}
void main()
{
	_beginthread(time, 0, NULL);
	uintptr_t hd;   //uintptr��һ�ָ߼�int����
	for (int i = 0; i < 5; i++)
	{
	    hd = _beginthread(print, 0, NULL);
		Sleep(2000);
	}			
	system("pause");
}