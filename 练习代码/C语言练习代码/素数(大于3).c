#include"stdio.h"
int main()
{
	int n,i;
	printf("plese enter a number,n=");
	scanf("%d",&n);
	for(i=2;i<=n-1;i++)
		if(n%i==0) break;
		if(i<n)printf("%d��������\n",n);
		else printf("%d������\n",n);
		return 0;

}


���ߣ�

int zhishu(int num)
{
	if(num ==2 || num == 3)
	{
		return 1;
	}
	else if(num <= 1)
	{
		return 0;
	}
	else if(num > 3 )
	{
		int flag = 1,i = 2;
		for(;i < num;i++)
		{
			if(num % i == 0)
			{
				flag = 0;
				break;
			}
			else flag = 1;
		}	
		return flag;
	}
}
int main()
{
A:	int num,flag;
	printf("������һ������:");
	scanf("%d",&num);
	zhishu(num);
	flag = zhishu(num);
	if(flag == 1)
	{
		printf("%d������!\n",num);
	}
	else 
	{
		printf("%d��������!\n",num);
	}
	goto A;
}