#include<stdio.h>
#include<stdlib.h>
void main()
{
	char oldname[100] = "E:\\编程垃圾\\2\\Debug\\1.txt";
	char newname[100] = "E:\\编程垃圾\\2\\Debug\\诗词.txt";
	if (rename(oldname, newname) == 0)
	{
		printf("改名成功\n");
	}
	else
	{
		printf("改名失败!\n");
	}
	system("pause");
}
//若不在一个目录下，则剪切到目的目录下再改名