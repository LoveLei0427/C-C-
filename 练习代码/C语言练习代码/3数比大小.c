#include<stdio.h>
#include<limits.h>
int main()
{	
		int a,b,c;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		printf("a=%d,b=%d,c=%d\n",a,b,c);
		int max = 0;//max装下最大值
		max = INT_MIN;//先令max为极小值
		a > max ? max = a : max;//a和max之间的最大值存入max
		b > max ? max = b : max;
		c > max ? max = c : max;
		printf("最大值是:%d\n",max);
}


	或者:	if(a>b)
		{
			if(a>c)
			{
				printf("最大值是a值是%d\n",a);
			}
			else
			{
				printf("最大值是c值是%d\n",c);
			}
		}
		else if(b>c)
		{
			printf("最大值是b值是%d\n",b);
		}
		else printf("最大值是c值是%d\n",c);*/
	}