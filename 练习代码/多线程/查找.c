#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >

struct Mystruct{
	int *startaddress;//要查找的首地址
	int length;		  //限定长度
	int *pflag;		  //为0表示找到，用于通知其他线程传递flag地址
	int num;		 //要查找的数据
	int bh;			//编号用于标记线程
};
typedef struct Mystruct	M;
void find(void *p)
{
	M *pstruct = (M *)p;
	//内存数据的遍历，从开始累加100个元素
	for (int *px = pstruct->startaddress; px < pstruct->startaddress+100; px++)
	{
		if (*px == pstruct->num)//判断是否找到数据
		{
			printf("******第%d个线程找到******%p,%d\n", pstruct->bh,px, *px);
			return;
		}
	}
	printf("第%d个线程里没有找到！\n",pstruct->bh);
}
void main()
{
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{

		a[i] = i;
	}
	//创建10个线程
	for (int j = 0; j < 10; j++)
	{
		//地址为a a+100 a+200...
		int *p = a + j * 100;
		M threaddata;//创建结构体
		threaddata.startaddress = p;
		threaddata.length = 100;//限定长度
		threaddata.bh = j;
		threaddata.num = 668;
		threaddata.pflag = NULL;
		_beginthread(find, 0, &threaddata);
		Sleep(10);
		//Windows多线程并不能完全节省时间，预留时间差创建线程
		//防止同一线程执行多次
	}

	system("pause");
}




同上类似：（有待考究）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
int flag = 0;//为0没找到
int *addfind = NULL;
struct Mystruct{
	int *startaddress;//要查找的首地址
	int length;		  //限定长度
	int *pflag;		  //为0表示找到，用于通知其他线程传递flag地址
	int num;		 //要查找的数据
	int bh;			//编号用于标记线程
	int **addr;		//传递指针地址，用于修改一级指针
};
typedef struct Mystruct	M;
void find(void *p)
{
	M *pstruct = (M *)p;
	//内存数据的遍历，从开始累加100个元素
	for (int *px = pstruct->startaddress; px < pstruct->startaddress+100; px++)
	{
		Sleep(100);
		if (*(pstruct->pflag) != 0)
		{
			printf("%d程未找到\n", pstruct->bh);
			return;
		}
		if (*px == pstruct->num)//判断是否找到数据
		{
			printf("******第%d个线程找到******%p,%d\n", pstruct->bh,px, *px);
			*(pstruct->pflag) = 1;//为1代表找到
			*(pstruct->addr) = px;
			return;
		}
	}
	printf("第%d个线程里没有找到！\n",pstruct->bh);
}
void main()
{
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;
	}
	M threaddata[10];//创建结构体数组,防止反复创建，读取同一片内存的问题
	//创建10个线程
	for (int j = 0; j < 10; j++)
	{
		//地址为a a+100 a+200...
		int *p = a + j * 100;
		threaddata[j].startaddress = p;
		threaddata[j].length = 100;//限定长度
		threaddata[j].bh = j;
		threaddata[j].num = 668;
		threaddata[j].pflag = &flag;//flag用于标识
		threaddata[j].addr = &addfind;
		_beginthread(find, 0, &threaddata[j]);
		Sleep(10);
		//Windows多线程并不能完全节省时间，预留时间差创建线程
		//防止同一线程执行多次
	}
	Sleep(10000);
	printf("\n\n%d,%p", *addfind, addfind);

	system("pause");
}