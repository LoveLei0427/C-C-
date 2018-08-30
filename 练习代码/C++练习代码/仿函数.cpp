/*
仿函数 创建函数指针 引用结构体内部或者一个类内部的函数
仿函数(functor)，就是使一个类的使用看上去像一个函数
*/
#include<iostream>
#include<functional>//处理函数

using namespace std;
using namespace std::placeholders;//占位符 后面_1_2用到

//结构体的数据是独立的 代码是共享的
struct Mystruct{
	void add(int a)
	{
		cout << a << endl;
	}
	void add2(int a, int b)
	{
		cout << a + b << endl;
	}

};

int main()
{	
	Mystruct struct1;

	/*自动变量声明函数指针  首先传递结构体 引用其中函数add,借助实体struct1，总共一个参数
	bind绑定 (引用的内部函数，绑定的实体对象，参数1，参数2...)
	可以预先把指定可调用实体的某些参数绑定到已有的变量，产生一个新的可调用实体，
	（1）bind预先绑定的参数需要传具体的变量或值进去，对于预先绑定的参数，是pass-by-value的
    （2）对于不事先绑定的参数，需要传std::placeholders进去，从_1开始，依次递增。placeholder是pass-by-reference的
    （3）bind的返回值是可调用实体，可以直接赋给std::function对象
    （4）对于绑定的指针、引用类型的参数，使用者需要保证在可调用实体调用之前，这些参数是可用的
    （5）类的this可以通过对象或者指针来绑定
	*/
	auto func = bind(&Mystruct::add,&struct1,_1);
	func(100);
	//cin.get();
	cout << endl;
	auto func2 = bind(&Mystruct::add2, &struct1, _1, _2);
	func2(100, 99);
	cin.get();
	/*
	或者根据类来引用函数
	创建函数指针   函数通过对象名来区别
	void (Mystruct::*p)(int a)=&MyStruct::add;

	*/
	getchar();
}