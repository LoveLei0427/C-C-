//������ ����ֵ ������Сֵ
#include<stdio.h>
#include<stdlib.h>
#define ABS(x) ((x)>0)?(x):((-1)*(x))
#define Li(x) x*x*x
#define Min(x,y) (x)>(y)?(y):(x)  //�������ű�֤������
void main()
{
	printf("%d", Li(10));
	printf("\n");
	printf("%d", ABS(-2));
	printf("\n");
	printf("%d", Min(9, 99));
	system("pause");
}