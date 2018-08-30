#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	while(1)
	{
		for(int i = 0x0; i <= 0xf; i++)
		{
			char syr[30];
			sprintf(str, "color %x%x",i 0xf-i);
			system(str);
			sleep(200);
		
		}	
	
	}	
}
或者：
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void main()
{	
	char str[20];
	char str1[60];
	int time = 0;
	while(1)
	{
		for(int i = 0;i <= 15;i++)
		{
		sprintf(str,"COLOR %x%x",i,15 - i);
		system(str);
		printf("\n%s",str);
		sprintf(str1,"title 程序运行了%d秒",time);
		time++;
		system(str1);
		Sleep(500);
		}
	}
	getchar();	
}