/*�ַ���λʵ�ּ���
1.txt�����Ժ󱣴浽jiami.txt,�����Ժ󱣴浽jiemi.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void jiami()
{
	FILE *fpr;//��ȡԴ�ļ�ָ��
	FILE *fpw;//Ŀ���ļ���ָ��
	char spath[100] = "E:\\�������\\2\\Debug\\1.txt";
	char dpath[100] = "E:\\�������\\2\\Debug\\jiami.txt";
	fpr = fopen(spath, "r");//�ö��ķ�ʽ����Ҫ���ܵ��ļ�
	fpw = fopen(dpath, "w");//��д�ķ�ʽ�����ܺ������д��Ŀ���ļ�
	if ((fpr == NULL) || (fpw == NULL))
	{
		perror("the false of file is:");//�����������
	}
	while (!feof(fpr))
	{
		char ch = fgetc(fpr);
		ch = ch + 1;
		fputc(ch, fpw);
	}
	fclose(fpr);
	fclose(fpw);
}
void jiemi()
{
	FILE *fpr;//��ȡԴ�ļ�ָ��
	FILE *fpw;//Ŀ���ļ���ָ��
	char spath[100] = "E:\\�������\\2\\Debug\\jiami.txt";
	char dpath[100] = "E:\\�������\\2\\Debug\\jiemi.txt";
	fpr = fopen(spath, "r");//�ö��ķ�ʽ�򿪼��ܺ���ļ�
	fpw = fopen(dpath, "w");//��д�ķ�ʽ�����ܺ������д��Ŀ���ļ�
	if ((fpr == NULL) || (fpw == NULL))
	{
		perror("the false of file is:");//�����������
	}
	while (!feof(fpr))
	{
		char ch = fgetc(fpr);
		ch = ch - 1;
		fputc(ch, fpw);
	}
	fclose(fpr);
	fclose(fpw);
}
void main()
{
	jiami();
	jiemi();
	system("pause...");
}

/*Ҳ����ָ���Ӷ���
void jiami(int num)...
���߽���λ�������
�߼��룬��������
liru:
void jiami(int a)
{
	ch=ch^a;
}
���߽����ַ�������ܽ���
void jiami(char a[],int length)//��������ͳ���
{
	...
	int i=0;//�����ʶλ����ʶȡ���������һλ
	while (!feof(fpr))
	{
		char ch = fgetc(fpr);
		if(i>length-1)//��������ʹ����ɣ�������ѭ��
		{
			i=0;
		}
		ch = ch + a[i];
		i++;
		fputc(ch, fpw);
	}
}
...
void main()
{
	char a[]="123456";
	int n = strlen(a);
}
���˷�����Ҫ�������ƶ�д�ķ�ʽ�����д���Ա�֤��ȷ����r->rb,w->wb��