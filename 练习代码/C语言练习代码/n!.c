#include<stdio.h>
int main()
{
	int fac(int n);							//fac��������
	int n;
	int y;
	printf("Input an integer number:");
	printf("\n");
	scanf("%d,&n");
	y=fac(n);
	printf("%d!=%d\n",n,y);
	return 0;
}
int fac(int n)								//����fac����
{
	int f;
	if(n<0)
		printf("n<0,data error!");
	else if(n==1||n==0)
		f=1;
	else f=fac(n-1)*n;
	return(f);
}
