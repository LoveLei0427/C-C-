#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void execmd(char *cmd,char *result)//���������Ҫִ�е�ָ��ͽ��
{
	char buffer[128] = { 0 };//���建����
	FILE *pipe = _popen(cmd, "r");//����һ���ܵ���ִ�ж�ȡָ��ѹܵ������ļ����д���
	if (pipe == NULL)
	{
		printf("����ʧ�ܣ�");
		return;
	}
	else
	{
		while (!feof(pipe))//�ж��ļ��Ƿ�ĩβ�����Ƿ��ط�0��û�оͼ���
		{
			if (fgets(buffer, 128, pipe))//��ȡ�ļ�������
			{
				strcat(result, buffer);//�����ַ�����������浽result
			}
		}
		_pclose(pipe);//�ر�
	}
}
void main()
{
	//system("tasklist");
	char output[8096] = { 0 };//�����ַ����������
	execmd("tasklist", output);//ִ��ָ����浽output
	printf("%s", output);
	if (strstr(output, "QQ.exe") == NULL)
	{
		printf("QQ�����ڣ�");
	}
	else
	{
		printf("QQ���ڣ�");
	}
	system("pause...");
}