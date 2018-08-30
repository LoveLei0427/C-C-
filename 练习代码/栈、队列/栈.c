#include<stdio.h>
#include<stdLib.h>
#define N 100
//定义栈结构体
struct stack
{
	int top;
	int data[N];//数组用于存放数据
};
struct stack mystack = { -1, { 0 } };
	//创建一个结构体变量-1代表没有元素，0将数组初始化为0
int isempty();//判断栈是否空
void setempty();//将栈置空或者设置为int型
int push(int data);//入栈
int pop();//出栈
int isempty()//1为空0表示不空
{
	if (mystack.top == -1)//代表没有元素
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
int push(int data)//1表示入栈成功反之为0
{
	if (mystack.top + 1 <= N - 1)//判断溢出
	{
		mystack.data[mystack.top + 1] = data;//数组上升一个接收新的数据
		mystack.top += 1;//下标前移一位

	}
	else
	{
		return 0;
	}
}
int pop()
{
	if (isempty() == 0)//不为0时不空,出栈
	{
		mystack.top -= 1;//下标减1
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