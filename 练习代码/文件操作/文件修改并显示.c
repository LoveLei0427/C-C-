//����ʵ�� ��������Ҫ����ļ�ĩβ��� HelloWorld!
 
























��ʵ�֣�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[60] = "E:\\�������\\2\\Debug";
	char outputpath[60] = "E:\\�������\\2\\Debug\\list.txt";
	char CMD[80];
	//��ʽ���ַ���ָ��鿴���е�txt�ļ�
	sprintf(CMD, "dir /b %s\\*.txt>%s", path, outputpath);
	system(CMD);//ִ��ָ����ļ��б������һ���ļ�
	char show[60];
	sprintf(show, "type %s", outputpath);
	system(show);
	system("pause");
}