#include<iostream>

// 函数模板实现通用，可以根据自有数据类型，进行优化
//结构体和类没有私有变量时才可以直接赋值初始化
//所有成员都是公有的类型可以赋值初始化

class info{
public:
	char name[20];
	double db;
	int data;
};

template<class T>void swap(T &a, T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "通用函数模板" << std::endl;
	std::cout << a << " " << b << std::endl;
}

//若无此函数 则运行结果为通用函数模板
template<>
void swap(info &info1, info &info2)
{
	//通过模板可以实现通用，针对自己的数据类型做出优化
	std::cout << "特有函数模板" << std::endl;
	info temp = info1;
	info1 = info2;
	info2 = temp;
}

int main()
{
	info info1 = { "hello", 20.9, 10 };
	info info2 = { "world", 20.8, 1 };
	swap(info1, info2);
	std::cout << info1.name <<  info1.db <<  info1.data << std::endl;
	std::cout << info2.name <<  info2.db <<  info2.data << std::endl;
	std::cin.get();
}
