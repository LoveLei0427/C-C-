#include<stdio.h>
#include<stdlib.h>
void main()
{
	char oldname[100] = "E:\\�������\\2\\Debug\\1.txt";
	char newname[100] = "E:\\�������\\2\\Debug\\ʫ��.txt";
	if (rename(oldname, newname) == 0)
	{
		printf("�����ɹ�\n");
	}
	else
	{
		printf("����ʧ��!\n");
	}
	system("pause");
}
//������һ��Ŀ¼�£�����е�Ŀ��Ŀ¼���ٸ���