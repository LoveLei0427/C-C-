#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	//ˢ�º�������뻺���������Զ���һЩ��������
	//��������һЩ���õ�����
	fflush(stdin);
	ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	system("pause");
}




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100];
	setvbuf(stdout, str, _IOFBF, 100);
	//ˢ����Ļ�������������ȫ����ģʽ���м�ʱ���
	fflush(stdout);
	printf("HelloWorld!");
	system("pause");
}