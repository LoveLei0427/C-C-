#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void main()
{
	char str[20] = "xhelloxgirlx!";
	char * p = str;
	char ch = 'x';
	while (*p!='\0')
	{
		if (*p==ch)
		{
			char *p1 = p;
			char *p2 = p + 1;
			while (*p2!='\0')
			{
				*p1 = *p2;
				p1++;
				p2++;
			}
			*p1 = '\0';
		}
		else
		{
			p++;
		}
	}
	printf("%s", str);
	system("pause...");
}














strstr() ��������һ���ַ�������һ���ַ����еĵ�һ�γ��֡��ҵ����������ַ�������ú������ص�һ��ƥ����ַ����ĵ�ַ�����δ�ҵ����������ַ������򷵻�NULL��

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void main()
{
	char allstr[30] = "hello c hello c++ hello c#!";
	char  str[6]="hello";
	char *p;
	while ((p=strstr(allstr,str))!=NULL)
	{
		int length = strlen(str);//��ȡҪɾ���ַ��ʹ�����
		char *p1 = p;//��ȡ��ǰλ��
		char *p2 = p + length;//��ȡҪɾ���ַ������λ��
		while (*p2 != '\0')
		{
			*p1 = *p2;//����ָ������ַ�������
			p1++;
			p2++;
		}
		*p1 = '\0';//��������
	}
	printf("%s", allstr);
	system("pause...");
}