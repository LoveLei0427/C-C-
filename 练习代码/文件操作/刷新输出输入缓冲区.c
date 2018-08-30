#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	//刷新后面的输入缓冲区，可以丢弃一些垃圾数据
	//继续输入一些有用的数据
	fflush(stdin);
	ch = getchar();
	printf("[%c]", ch);
	ch = getchar();
	printf("[%c]", ch);
	system("pause");
}




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100];
	setvbuf(stdout, str, _IOFBF, 100);
	//刷新屏幕输出缓冲区，对全缓冲模式进行及时输出
	fflush(stdout);
	printf("HelloWorld!");
	system("pause");
}