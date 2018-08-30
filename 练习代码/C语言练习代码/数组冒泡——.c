#include<stdio.h>
#include<stdlib.h>
void sort(int *p,int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if ((*(p + j)) < (*(p + j + 1)))
			{
				int temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
}
void main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("原数组是:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",a[i]);
	}
	sort(a, 10);
	printf("冒泡排序后输出顺序由大到小是:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",a[i]);
	}
	getchar();
}