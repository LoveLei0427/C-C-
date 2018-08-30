#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
// 函数模板实现通用，可以根据自有数据类型，进行优化
//结构体和类没有私有变量时才可以直接赋值初始化
//所有成员都是公有的类型可以赋值初始化 如果类有私有成员变量 不能用{}初始化

class info{
public:
	char name[20];
	int data;  
	char *p;
	void set(int x)
	{
		this->num = x;
	}
	int get()
	{
		return this->num;//副本机制 不会影响原name=0
	}
private:
	int  num=0;
	//~info();
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
	//实现深度拷贝 为结构体里指针*p赋值 防止一个指针指向的内存释放后 另一指针找到不到地址

}

int main()
{
	info info1;
	info info2;
	std::strcpy(info1.name, "hello");
	std::strcpy(info2.name, "world");
	info1.data = 100;
	info2.data = 200;
	info1.p = new char[30];
	std::strcpy(info1.p, "地址1");
	info2.p = new char[30];
	std::strcpy(info2.p, "地址2");
	swap(info1, info2);
	info1.set(11);
	info2.set(22);
	std::cout << info1.name <<" "<<info1.get() <<" "<< info1.data <<" "<<info1.p<< std::endl;
	std::cout << info2.name <<" "<<info2.get() <<" "<< info2.data <<" "<<info2.p<< std::endl;
	std::cin.get();
}