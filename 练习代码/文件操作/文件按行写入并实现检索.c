//�ļ����������(���м���)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp;
	char s[5] = "��";
	fp = fopen("E:\\�������\\2\\Debug\\ʫ��.txt","r");
	if (fp == NULL)
	{
		printf("error");
	}
	char str[200] = { 0 };
	while (fgets(str, 200, fp))
	{
		//puts(str);
		char *p = strstr(str,s);
		if (p == NULL)
		{
			//�����������һ�仰��û��Ҫ����ַ�������
		}
		else
		{
			puts(str);//����������Ŀ���ַ��������һ��
		}
	}
	system("pause");
}