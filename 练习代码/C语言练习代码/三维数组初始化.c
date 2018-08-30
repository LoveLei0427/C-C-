#include<stdio.h>
int main()
{
	int i , j , k , a = 0;
	int b[3][4][5];				//5个面 每面4行 每行3列
	printf("\n%d\n",sizeof(b));
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<5;k++)
			{
				b[i][j][k] = a + 1;
				printf("%6d",b[i][j][k]);
				a++;
			}
			printf("\n");
		}
		printf("\n\n");
	}
		getchar();
		return 0;	
} 