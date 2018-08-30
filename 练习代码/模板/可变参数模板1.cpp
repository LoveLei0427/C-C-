//可变参数函数模板通常是递归的。第一步调用处理包中的第一个实参，然后用剩余的实参调用自身。为了终止递归，我们还需要定义一个非可变参数的函数模板
#include<iostream>
#include<vector>
#include<string>
void show(){}//空函数 预留接口作用 不可去
template<class T, class...Args>void show(T value, Args...rest)
{
	std::cout << value << std::endl;
	show(rest...);//继续传递

} 

int main(void)
{ 
	
	int a = 10, b = 20, c = 15;
	double i = 1.1, j = 20.1;
	std::string s = "hello";
	show(a, b, c);
	show(a, i, s);
	std::cin.get();
}