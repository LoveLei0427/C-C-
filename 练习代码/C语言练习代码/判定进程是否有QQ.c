#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void execmd(char *cmd,char *result)//定义参数，要执行的指令和结果
{
	char buffer[128] = { 0 };//定义缓冲区
	FILE *pipe = _popen(cmd, "r");//创建一个管道，执行读取指令，把管道当作文件进行处理
	if (pipe == NULL)
	{
		printf("运行失败！");
		return;
	}
	else
	{
		while (!feof(pipe))//判断文件是否到末尾，若是返回非0，没有就继续
		{
			if (fgets(buffer, 128, pipe))//读取文件缓冲区
			{
				strcat(result, buffer);//连接字符串，结果保存到result
			}
		}
		_pclose(pipe);//关闭
	}
}
void main()
{
	//system("tasklist");
	char output[8096] = { 0 };//定义字符串接受输出
	execmd("tasklist", output);//执行指令，保存到output
	printf("%s", output);
	if (strstr(output, "QQ.exe") == NULL)
	{
		printf("QQ不存在！");
	}
	else
	{
		printf("QQ存在！");
	}
	system("pause...");
}