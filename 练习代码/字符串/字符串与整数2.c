//������25678��Ϊ�ַ��������25678�������
#include<stdio.h>
#include<stdlib.h>
#define FAUSE -1
void main()
{
	char str[10] = { 0 };
	int num = 25678;
	int i,wei = 0, inum = num;
	for (inum = num; inum; inum /= 10)
	{
		wei++;//ͳ��������λ��
	}
	printf("����ת����������%dλ\n", wei);
	for (i = wei - 1; num; num /= 10,i--)
	{
		str[i] = num % 10 + 48;
		
	}
	printf("%s", str);
	system("pause");
}