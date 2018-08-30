//文件分割
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char path[100] = "E:\\编程垃圾\\2\\Debug";//文件路径
	char filename[100] = "music.mp3";//待分割文件名
	char lastpath[180];
	sprintf(lastpath, "%s\\%s", path, filename);//构建文件路径
	int filesize = 0;
	FILE *fp;
	fp = fopen(lastpath, "rb");//以二进制方式读写文件
	if (fp == NULL)
	{
		perror("The false of file is：");
		return;
	}
	fseek(fp,0,SEEK_END);//将文件指针移动到末尾
	filesize = ftell(fp);//获取文件大小
	printf("the size of the file is：%d\n", filesize);
	int size = 1024 * 1024;//设置要分割的子模块大小
	int N = 0;//标志一个文件能被分割成多少块
	if (filesize % size == 0)
	{
		N = filesize / size;
	}
	else
	{
		N = filesize / size + 1;
	}
	fseek(fp, 0, SEEK_SET);//将文件指针移动到开头
	char listpath[100] = "E:\\编程垃圾\\2\\Debug\\3.txt";//存储分割成多少块以及每块的文件名
	FILE *plist = fopen(listpath, "w");//按写入方式打开
	for (int i = 0; i < N; i++)//针对每一子模块处理
	{
		char temppath[100];//存储每一子模块的路径
		sprintf(temppath, "%s\\%d%s", path, i, filename);//构建每一块文件名
		printf("%s\n", temppath);//显示每个子模块路径及文件名
		fputs(temppath, plist);//将每一块的路径写入list.txt
		fputc('\n', plist);//写入一个换行符
		FILE * pb = fopen(temppath, "wb");//按二进制方式打开文件
		if (i < N)
		{
			for (int j = 0; j < size; j++)
			{
				int ch1 = fgetc(fp);//读取一个字符
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
	fclose(plist);//关闭列表文件
	fclose(fp);//关闭读取的文件
	system("pause");
}

//文件合并


