����һ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 1;
	num = num << 31;
	int data ;
	printf("������һ����:");
	scanf("%d", &data);
	for (int i = 1; i <= 32; i++)
	{
		printf("%d", (num&data ? 1 : 0));
		data <<= 1;
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	system("pause...");
}


������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct bits
{
	unsigned char bit1:1;
	unsigned char bit2:1;
	unsigned char bit3:1;
	unsigned char bit4:1;
	unsigned char bit5:1;
	unsigned char bit6:1;
	unsigned char bit7:1;
	unsigned char bit8:1;
};
int main()
{
	struct bits *p;
	p = (struct bits *)malloc(sizeof(struct bits) * 4);//�����ڴ�
	int *p1;
	p1 = (int *)p;//�����ڴ�
	*p1 = 0;
	printf("������һ����:");
	scanf("%d", p1);
	for (int i = 3;i >= 0; i--) //���ֽ���ǰ�����ֽ��ں�
	{

		printf("%d%d%d%d%d%d%d%d",p[i].bit8,p[i].bit7,p[i].bit7,p[i].bit5,
								  p[i].bit4,p[i].bit3,p[i].bit2,p[i].bit1);
	}
	system("pause...");
}
/*
0000 0001
0000 0000
0000 0000
0000 0000
*/