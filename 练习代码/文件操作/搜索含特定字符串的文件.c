#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[30] = "ǧɽĺѩ";//Ҫ���ҵ��ַ���
	char path[50] = "E:\\�������\\2\\Debug\\1.txt";
	char cmd[100];
	sprintf(cmd, "find /n \"%s\" \"%s\" ", str, path);
	system(cmd);
	system("pause");
}


/*
�÷���FIND [/V] [/C] [/N] [/OFF[LINE]] "string" [[drive:][path]filename[ ...]]
������
/V ��ʾ����δ����ָ���ַ������С�
/C ����ʾ�����ַ�����������
/N ��ʾ�кš�
/I �����ַ���ʱ���Դ�Сд��
/OFF[LINE] ��Ҫ���������ѻ����Լ����ļ���
"string" ָ��Ҫ���������ִ���
[drive:][path]filename
ָ��Ҫ�������ļ���
���û��ָ��·����FIND ����������Ļ�������һ������������֡�

*/