#include"stdio.h"
int main()
{
	int gg1(int a,int b);
	int gg2(int a,int b);
	int a,b,m,n;
	scanf("%d,%d",&a,&b);
	m=gg1(a,b);
	n=gg2(a,b);
    printf("最大公约数是%d\n最小公倍数是%d\n",m,n);
	return 0;
}
		int gg1(int a,int b)
		{
		int i,c;
		c=a>b?b:a;
		for(i=c;i>=1;i--)
		{
			if((a%i==0)&&(b%i==0)) break;
		}
		
		return i;
		}	
		int gg2(int a,int b)
		{
		int c;
	 	c=gg1(a,b);
	
		return (a*b)/c;
		}
