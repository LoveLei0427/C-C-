//非递归实现
/*
#include<stdio.h>
int main()
{
	int flag;
	int i;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i=0; i < 9; i++)
	{
		if (a[i]>a[i + 1])
		{
			flag = 0;
			break;
		}
		else flag = 1;
	}
	if (flag == 0)
		printf("非递增");
	else
		printf("递增");
	getchar();

}*/
	
	//递归实现
	#include<stdio.h>
	int a[10] = {1,2,3,4,6,2,7,8,9,10};
	int checking(int n)
	{
		if(n==8)
		{
			return (a[n]<=a[n+1]);
		}
		else
		{
			return	((a[n]<=a[n+1])&&checking(n+1));
		}
	}
	int main()
	{
		int flag = checking(0);
		if (flag == 0)
			printf("非递增");
		else
			printf("递增");
		getchar();
	}
	