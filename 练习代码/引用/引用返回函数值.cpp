#include<iostream>
using namespace std;
int a[]={1,3,5,7,9};
int &index(int);		//声明函数返回一个整数类型的引用
int main()
{
	index(2)=25;		//将函数调用放在赋值运算符左边，等价于将啊[2]赋值为25
	cout<<index(2)<<endl;//输出数组元素a[2]的值
	return 0;
}
int &index(int i)		
{
	return a[i];
}
