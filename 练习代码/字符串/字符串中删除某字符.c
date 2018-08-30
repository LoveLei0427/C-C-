#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char str[30] = "hello world,hello c,hello cpp";
	char ch = 'c';
	char empty[30] = { 0 };
	char *p = str;
	int i = 0;
	while (*p != '\0')
	{
		if (*p != 'c')
		{
			empty[i] = *p;
			i++;
		}
		p++;
	}
	printf("%s\n", empty);
	system("pause...");
}