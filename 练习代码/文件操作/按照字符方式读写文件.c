//��д�ļ����ݲ���ʾ������̨��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	fp = fopen("E:\\�������\\2\\Debug\\ʫ��.txt","r");
	if (fp == NULL)
	{
		perror("the false of the file is:");
	}
	else
	{
		while (!feof(fp))
		{			//��fp�Ѿ�ָ���ļ�ĩβ,��feof(fp)����ֵΪ						//���桱,�����ط���ֵ;���򷵻�0��
			char ch = getc(fp);
			putchar(ch);
		}
	}
	fclose(fp);
	system("pause");
}