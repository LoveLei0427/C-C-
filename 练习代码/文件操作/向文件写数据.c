//���ļ�д�����ݣ�

1. ����Echo������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100] = "i love u";
	char des[100] = "E:\\�������\\2\\Debug\\6.txt";
	char cmd[100];
	sprintf(cmd, "echo %s>>%s", str, des); // ">>"׷��д�뵽�ļ���, ">"����д��
	system(cmd);       
	system("pause");
}

2.�ļ���ʽʵ��
	FILE *fp;
	fp =fopen("E:\\�������\\2\\Debug\\6.txt","w");
	if (fp == NULL)
	{
		printf("error");
	}
	else
	{
		char str[100] = "i love u";
		int length = strlen(str);
		for (int i = 0; i<length; i++)//��ȡ�ַ����ȣ�һ���ַ�һ���ַ�д��
		{
			fputc(str[i],fp);
		}
	}
	fclose(fp);

3.����������ļ�д�� Ctrl+Z����
		char ch = getchar();
		while (ch!=EOF)
		{
			fputc(ch, fp);
			ch = getchar();
		}
	
