#include<stdio.h>
#include<stdLib.h>
#define N 100
//����ջ�ṹ��
struct stack
{
	int top;
	int data[N];//�������ڴ������
};
struct stack mystack = { -1, { 0 } };
	//����һ���ṹ�����-1����û��Ԫ�أ�0�������ʼ��Ϊ0
int isempty();//�ж�ջ�Ƿ��
void setempty();//��ջ�ÿջ�������Ϊint��
int push(int data);//��ջ
int pop();//��ջ
int isempty()//1Ϊ��0��ʾ����
{
	if (mystack.top == -1)//����û��Ԫ��
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void setempty()
{
	mystack.top = -1;
}
int push(int data)//1��ʾ��ջ�ɹ���֮Ϊ0
{
	if (mystack.top + 1 <= N - 1)//�ж����
	{
		mystack.data[mystack.top + 1] = data;//��������һ�������µ�����
		mystack.top += 1;//�±�ǰ��һλ

	}
	else
	{
		return 0;
	}
}
int pop()
{
	if (isempty() == 0)//��Ϊ0ʱ����,��ջ
	{
		mystack.top -= 1;//�±��1
		return mystack.data[mystack.top + 1];
	}
	else
	{
		return -1;
	}
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i ;
	for (i = 0; i < 10; i++)
	{
		push(a[i]);
	}
	while (isempty() != 1)
	{
		printf("%d\n", pop());
	}
	system("pause");
}