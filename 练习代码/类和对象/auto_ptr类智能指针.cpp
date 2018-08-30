/*
auto_ptr是模板类  用于动态内存分配
定义了类似指针的对象 可以将new直接或间接获得的地址赋给这种对象 
当对象过期时 析构函数将自动使用delete释放
注意：1包含头文件<memory>2auto_ptr的析构函数是显式的3和new一起使用而不是new[]
*/
#include<iostream>
#include<stdlib.h>
#include<memory>
#include<string>
using namespace std;

void SmartPointer(string &str)
{
	auto_ptr<string>pd(new string(str));
	/*
	auto_ptr<string>pd;
	string *str=new string;
	pd = str;
	或者auto_ptr<string>pd=str;
	错误 不存在指针到auto_ptr对象的隐式类型转换
	*/
	cout << *pd<< endl;
}
void main()
{
	string s("C++!");
	SmartPointer(s);
	system("pause");
}