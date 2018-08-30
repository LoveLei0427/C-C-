#include<stdio.h>
int main()
{
	int a[10]={60,61,62,63,64,65,66,67,68,69};
	int s = 0,x = 9,z;
	int num;
	printf("ÇëÊäÈënumµÄÖµ(60~69):\n");
	scanf("%d",&num);
	while(s<x)
	{
		z = (s + x) / 2;
		printf("s = %d z = %d x = %d\n",a[s],a[z],a[x]);
		if(num == a[z])
		{
			printf("Find!!!");
			break;
		}
		else if(num > a[z])
		{
			s = z + 1;
		}
		else if(num < a[z])
		{
			x = z - 1;
		}
	}
	printf("\n");
}