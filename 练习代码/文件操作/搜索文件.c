#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "C:\\Users\\Administrator\\Desktop";//Դ�ļ�·��
	char filename[300] = "*.*";//Ҫ�������ļ���������
	char out[100] = "C:\\Users\\Administrator\\Desktop\\out.txt";//Ŀ���ļ�·�����ļ�
	char cmd[512];
	sprintf(cmd, "for /r \"%s\" %%i in (%s) do @echo %%i", path, filename,out);
	system(cmd);//ִ���ļ�
	char show[100];
	sprintf(show, "type %s", out);
	system(show);//��ʾĿ���ļ�����
	system("pause...");
}