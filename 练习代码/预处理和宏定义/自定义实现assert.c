#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>
#ifndef DEBUG
#define myassert(x)
#else
#define myassert(x)\
if(!(x)) \
{\
	printf("MyAssert(%s)��ʼ���...\n", #x); \
	printf("��ǰ����ĺ�������%s,�ļ�����%s,�к���%d\n", __FUNCTION__, __FILE__, __LINE__); \
	char str[100]; \
	sprintf(str, "��ǰ����ĺ�������%s,�ļ�����%s,�к���%d\n", __FUNCTION__, __FILE__, __LINE__); \
	MessageBoxA(0, str, "ErrorInformation", 0);\
}
#endif
void main()
{
	int a = 100;
	myassert(a < 100);
	system("pause");
}