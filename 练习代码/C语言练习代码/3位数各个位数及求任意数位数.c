#include<stdio.h>
int main()
{	
     while(1)
     {
	int num;
	printf("������һ����λ��:");
	scanf("%d",&num);
	int gewei = num % 10;
	int shiwei = num/10%10;
	int baiwei =  num/100%10;
	int sum = gewei + shiwei +baiwei;
	printf("��λ=%d,ʮλ=%d,��λ=%d,����λ��֮����:%d\n",gewei,shiwei,baiwei,sum);
      }
	return 0;
}



2��

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
	printf("������һ������:");
	scanf("%d",&num);
	printf("�������%dλ��!\n",wei(num));
	goto A;
}

