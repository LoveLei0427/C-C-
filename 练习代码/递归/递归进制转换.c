//ʮ����ת��Ϊ������
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdLib.h>
void tentotwo(int num)
{
	if (num == 0)
	{
		//���Ҫת��������0�򲻽��иı䣻
	}
	else
	{
		int m = num % 2;//��Ҫʵ��ʮ����ת��Ϊ�˽�������԰�,��ͬ
		num = num / 2;
		tentotwo(num);
		printf("%d", m);//�ݹ����֮���ӡ��Ϊ�����ӡ��֮�������
	}
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("\n");
	tentotwo(n);
	system("pause");
}