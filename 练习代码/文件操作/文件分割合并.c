//�ļ��ָ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "E:\\�������\\2\\Debug";//�ļ�·��
	char filename[100] = "music.mp3";//���ָ��ļ���
	char lastpath[180];
	sprintf(lastpath, "%s\\%s", path, filename);//�����ļ�·��
	int filesize = 0;
	FILE *fp;
	fp = fopen(lastpath, "rb");//�Զ����Ʒ�ʽ��д�ļ�
	if (fp == NULL)
	{
		perror("The false of file is��");
		return;
	}
	fseek(fp,0,SEEK_END);//���ļ�ָ���ƶ���ĩβ
	filesize = ftell(fp);//��ȡ�ļ���С
	printf("the size of the file is��%d\n", filesize);
	int size = 1024 * 1024;//����Ҫ�ָ����ģ���С
	int N = 0;//��־һ���ļ��ܱ��ָ�ɶ��ٿ�
	if (filesize % size == 0)
	{
		N = filesize / size;
	}
	else
	{
		N = filesize / size + 1;
	}
	fseek(fp, 0, SEEK_SET);//���ļ�ָ���ƶ�����ͷ
	char listpath[100] = "E:\\�������\\2\\Debug\\3.txt";//�洢�ָ�ɶ��ٿ��Լ�ÿ����ļ���
	FILE *plist = fopen(listpath, "w");//��д�뷽ʽ��
	for (int i = 0; i < N; i++)//���ÿһ��ģ�鴦��
	{
		char temppath[100];//�洢ÿһ��ģ���·��
		sprintf(temppath, "%s\\%d%s", path, i, filename);//����ÿһ���ļ���
		printf("%s\n", temppath);//��ʾÿ����ģ��·�����ļ���
		fputs(temppath, plist);//��ÿһ���·��д��list.txt
		fputc('\n', plist);//д��һ�����з�
		FILE * pb = fopen(temppath, "wb");//�������Ʒ�ʽ���ļ�
		if (i < N)
		{
			for (int j = 0; j < size; j++)
			{
				int ch1 = fgetc(fp);//��ȡһ���ַ�
				fputc(ch1, pb);
			}
		}
		else
		{
			for (int j = 0; j < filesize-(N-1)*size; j++)
			{
				int ch2 = fgetc(fp);
				fputc(ch2, pb);
			}
		}
		fclose(pb);
	}
	fclose(plist);//�ر��б��ļ�
	fclose(fp);//�رն�ȡ���ļ�
	system("pause");
}

//�ļ��ϲ�


