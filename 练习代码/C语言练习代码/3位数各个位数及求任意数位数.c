#include<stdio.h>
int main()
{	
     while(1)
     {
	int num;
	printf("请输入一个三位数:");
	scanf("%d",&num);
	int gewei = num % 10;
	int shiwei = num/10%10;
	int baiwei =  num/100%10;
	int sum = gewei + shiwei +baiwei;
	printf("个位=%d,十位=%d,百位=%d,各个位数之和是:%d\n",gewei,shiwei,baiwei,sum);
      }
	return 0;
}



2：

int wei(int num)
{
	int i = 0;
	for(;num;num=num/10)
	{	
		i++;
	}
	return i;
}
void main()
{
A:	int num;
	printf("请输入一个整数:");
	scanf("%d",&num);
	printf("这个数是%d位数!\n",wei(num));
	goto A;
}

