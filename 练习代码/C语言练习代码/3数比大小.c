#include<stdio.h>
#include<limits.h>
int main()
{	
		int a,b,c;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		printf("a=%d,b=%d,c=%d\n",a,b,c);
		int max = 0;//maxװ�����ֵ
		max = INT_MIN;//����maxΪ��Сֵ
		a > max ? max = a : max;//a��max֮������ֵ����max
		b > max ? max = b : max;
		c > max ? max = c : max;
		printf("���ֵ��:%d\n",max);
}


	����:	if(a>b)
		{
			if(a>c)
			{
				printf("���ֵ��aֵ��%d\n",a);
			}
			else
			{
				printf("���ֵ��cֵ��%d\n",c);
			}
		}
		else if(b>c)
		{
			printf("���ֵ��bֵ��%d\n",b);
		}
		else printf("���ֵ��cֵ��%d\n",c);*/
	}