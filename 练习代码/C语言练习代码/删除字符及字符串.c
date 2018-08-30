#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void main()
{
	char str[20] = "xhelloxgirlx!";
	char * p = str;
	char ch = 'x';
	while (*p!='\0')
	{
		if (*p==ch)
		{
			char *p1 = p;
			char *p2 = p + 1;
			while (*p2!='\0')
			{
				*p1 = *p2;
				p1++;
				p2++;
			}
			*p1 = '\0';
		}
		else
		{
			p++;
		}
	}
	printf("%s", str);
	system("pause...");
}














strstr() 函数搜索一个字符串在另一个字符串中的第一次出现。找到所搜索的字符串，则该函数返回第一次匹配的字符串的地址；如果未找到所搜索的字符串，则返回NULL。

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void main()
{
	char allstr[30] = "hello c hello c++ hello c#!";
	char  str[6]="hello";
	char *p;
	while ((p=strstr(allstr,str))!=NULL)
	{
		int length = strlen(str);//获取要删除字符型串长度
		char *p1 = p;//获取当前位置
		char *p2 = p + length;//获取要删除字符串后继位置
		while (*p2 != '\0')
		{
			*p1 = *p2;//根据指针进行字符串拷贝
			p1++;
			p2++;
		}
		*p1 = '\0';//填充结束符
	}
	printf("%s", allstr);
	system("pause...");
}