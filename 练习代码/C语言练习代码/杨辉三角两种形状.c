#include<stdio.h>
#define	N	10
int main()
{
	int i=0,j=0;
	int a[N][N] = {0};
	for(i = 0; i < N; i ++)
	{
		for(j = 0; j <= i;j++)
		{
			if((j==0)||(i==j))
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
			printf("%-5d",a[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < N; i ++)
	{
		printf("%*d",20-i*2,a[i][0]);	//打印第一列 "%*d"
		for(j = 1; j <= i;j++)
		{
			printf("%4d",a[i][j]);      
		}
		printf("\n");
	}
}