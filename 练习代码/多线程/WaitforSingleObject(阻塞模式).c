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
	���̴߳�11�뿪ʼûһ�����һ���߳�֪��15��Ϊֹ
	*/
	while(1)
	{
		//ÿ����5Sʱ��ִ��һ���߳�
		if (i > 5)
		{
			printf("%d	%d\n", i,*px);
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
	    HANDLE hd = _beginthread(print, 0, &i);
		//WaitforSingleObjectΪ����ִ��ģʽ���ǲ���
		WaitForSingleObject(hd, INFINITE);//INFINITEΪ�����ڵȴ�
	}			
	system("pause");
}