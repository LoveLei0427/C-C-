#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
int add(int n,int m)
{
	return m+n;
}
int maxdata(int n, int m)
{
	return n > m ? n : m;
}
int mindata(int n, int m)
{
	return n < m ? n : m;
}
int choose(int n,int m,int(*p)(int,int))
{
	return p(n, m);
}
void main()
{
	int n = 9, m = 11;
	int num;
	while (1)
	{
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("%d��%d�������нϴ����:", n, m);
			printf("%d\n", choose(n, m, maxdata));
			break;
		case 2:
			printf("%d��%d�������н�С����:", n, m);
			printf("%d\n", choose(n, m, mindata));
			break;
		case 3:
			printf("%d��%d�������ĺ���:", n, m);
			printf("%d\n", choose(n, m, add));
			break;
		default:
			break;
		}
	}
	system("pause");
}