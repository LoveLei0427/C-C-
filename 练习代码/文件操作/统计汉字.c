GBK�涨�����֣����ģ����ģ������ı��ȵ�һ���ֽڴ���128

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char path[100] = "E:\\�������\\2\\Debug\\1.txt";
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("the false of file is:");//�����������
	}
	int x;//fhetcde����ֵ��int���ͣ�intռ�ĸ��ֽ����洢���ֱ��룬��������char
	int hanzi = 0;
	while ((x = fgetc(fp))!=EOF)
	{
		if (x > 128)
		{
			x = fgetc(fp);//����ռ�����ֽڣ�����ǰ��һ���ֽ�
			hanzi++;
		}
	}
	printf("hanzi=%d", hanzi);
	fclose(fp);
	system("pause...");
}

/*
��ʱ��ֻ�ǵ����жϺ��ֵĸ������Ժ��ֱ����ôif���ɸ�Ϊ
{
	int a = fgetc(fp);
		if()
		  {
			...
		   }	
}
*/