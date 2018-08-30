#include"stdio.h"
int main()
{
	int	max4(int x,int y,int z,int w);
	int x,y,z,w,max;
	printf("puts four nums:");
	scanf("%d,%d,%d,%d",&x,&y,&z,&w);
	max=max4(x,y,z,w);
	printf("max is %d\n",max);
	return 0;
}
	int	max4(int x,int y,int z,int w)
	{
	int max2(int x,int y);
	int a;
	a=max2(x,y);
	a=max2(a,z);
	a=max2(a,w);
	return (a);}
	int max2(int x,int y)
	{	int b;
		if(x>y)b=x;
		else b=y;
		return (b);
	}
	
	
	

