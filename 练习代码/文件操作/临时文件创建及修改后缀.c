#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//������ʱ�ļ���tmpfile�߱������ƶ�дȨ�� 
//�ر��ļ���������Զ�ɾ��
//����ʱ�ļ��޸�Ϊ.txt��ʽ
void main()
{
	FILE *tmpfile;//�����ļ�ָ��
	char path[100];//����·����������ʱ�ļ���
	tmpnam(path);//����һ��Ψһ���ļ������浽path
	char *p = path;   //�޸��ļ�Ϊ.txt��ʽ
	while (*p != '\0')
	{
		if (*p == '.')
		{
			*p = '0';
		}
		p++;
	}
	strcat(path, ".txt");
	printf("�ļ�·����%s", path);
	tmpfile = fopen(path, "w+");//���տɶ���д�ķ�ʽ��
	if (tmpfile == NULL)
	{
		perror("the false of file is:");
	}
	fputs("��������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ��", tmpfile);
	rewind(tmpfile);
	char str[512];
	fgets(str, 512, tmpfile);
	fclose(tmpfile);
	system("pause...");
}