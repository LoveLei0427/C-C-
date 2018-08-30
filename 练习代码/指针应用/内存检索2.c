//************代码二在指定地址区间内检索到值为123的变量地址并改变----模块实现
//使用进程、线程、进程模块、进程窗口、进程内存信息查看工具XueTr
//操作步骤同1
#include<stdio.h>
#include<stdlib.h>
_declspec(dllexport) void go()
{
	void *startp = (void *)0x1db80000;
	void *endp = (void *)0x1db81000;//定义扫描的地址区间
	for (char *p = startp; p != endp; p++)//每次移动一个字节保证若有四个字节分开时数据丢失的情况
	{
		int *px = (int *)p;//类型转换为int向前读取四个字节，检索值是不是为123
		if (*px == 123)
		{
			*px = 555;//检索并赋值
		}
	}
	getchar();
}



//搜索内存实现网吧自动充值
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
_declspec(dllexport) void go()
{
	void *startp = (void *)0x1db80000;
	void *endp = (void *)0x1db81000;
	int *valuep = NULL;//防止野指针;
	for (char *p = startp; p!= endp; p++)
	{
		int *px = (int *)p;
		if (*px == 555)
		{
			*px = 100;
			valuep = px;
			break;//找到需要自改的值就跳出
		}
	}
	while (1)
	{
		if(*valuep <= 100)
		{
			*valuep = 200;
		}
		Sleep(5000);//5S检测一次低于100就充值为200
	}
		
	getchar();
}
