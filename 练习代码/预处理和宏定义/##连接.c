#include<stdio.h>
#include<stdlib.h> 
#define I(x) X##x
#define P(x) printf("%s=%d",#x,x)
void main()
{
	int X(1) = 1111;  //I(1)�ȼ���I1��
	P(X(1));
	system("pause");
} 