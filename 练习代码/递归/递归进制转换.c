//十进制转换为二进制
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdLib.h>
void tentotwo(int num)
{
	if (num == 0)
	{
		//如果要转换的数是0则不进行改变；
	}
	else
	{
		int m = num % 2;//若要实现十进制转换为八进制则除以八,下同
		num = num / 2;
		tentotwo(num);
		printf("%d", m);//递归调用之后打印即为逆序打印反之正序输出
	}
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("\n");
	tentotwo(n);
	system("pause");
}