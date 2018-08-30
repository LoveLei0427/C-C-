#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a = 100, b = 99, c = 0;
	_asm
	{
		mov eax, c
		add eax, a
		add eax, b
		mov c, eax
	}
	printf("c=%d", c);
	system("pause");
}