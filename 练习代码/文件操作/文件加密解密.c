/*字符移位实现加密
1.txt加密以后保存到jiami.txt,解密以后保存到jiemi.txt
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void jiami()
{
	FILE *fpr;//读取源文件指针
	FILE *fpw;//目的文件的指针
	char spath[100] = "E:\\编程垃圾\\2\\Debug\\1.txt";
	char dpath[100] = "E:\\编程垃圾\\2\\Debug\\jiami.txt";
	fpr = fopen(spath, "r");//用读的方式打开需要加密的文件
	fpw = fopen(dpath, "w");//用写的方式将加密后的数据写到目的文件
	if ((fpr == NULL) || (fpw == NULL))
	{
		perror("the false of file is:");//输出错误类型
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
	FILE *fpr;//读取源文件指针
	FILE *fpw;//目的文件的指针
	char spath[100] = "E:\\编程垃圾\\2\\Debug\\jiami.txt";
	char dpath[100] = "E:\\编程垃圾\\2\\Debug\\jiemi.txt";
	fpr = fopen(spath, "r");//用读的方式打开加密后的文件
	fpw = fopen(dpath, "w");//用写的方式将解密后的数据写到目的文件
	if ((fpr == NULL) || (fpw == NULL))
	{
		perror("the false of file is:");//输出错误类型
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

/*也可以指定加多少
void jiami(int num)...
或者进行位运算加密
逻辑与，或，异或加密
liru:
void jiami(int a)
{
	ch=ch^a;
}
或者进行字符数组加密解密
void jiami(char a[],int length)//传入数组和长度
{
	...
	int i=0;//定义标识位，标识取出数组的哪一位
	while (!feof(fpr))
	{
		char ch = fgetc(fpr);
		if(i>length-1)//加密数组使用完成，就重新循环
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
但此方法需要按二进制读写的方式读入和写出以保证精确，即r->rb,w->wb；