//将整数25678变为字符串输出“25678”并输出
#include<stdio.h>
#include<stdlib.h>
#define FAUSE -1
void main()
{
	char str[10] = { 0 };
	int num = 25678;
	int i,wei = 0, inum = num;
	for (inum = num; inum; inum /= 10)
	{
		wei++;//统计整数的位数
	}
	printf("所需转换的整数有%d位\n", wei);
	for (i = wei - 1; num; num /= 10,i--)
	{
		str[i] = num % 10 + 48;
		
	}
	printf("%s", str);
	system("pause");
}