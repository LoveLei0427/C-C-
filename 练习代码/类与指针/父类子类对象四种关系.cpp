/*
父类指针引用父类对象 完全正常引用
子类指针引用子类对象就会覆盖父类的同名函数
父类指针引用子类对象只能引用父类中的函数
子类指针引用父类对象子类不涉及内部数据的函数会调用成功反之失败 子类指针必须使用
子类对象->父类名：：方法（）的格式才能引用父类函数

数据是私有的，代码是共享的
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(){
		this->strf = "Base";
	}
	~Base(){}
	void print(){
		cout << this->strf << endl;
	}
	void Demof(){
		cout << "I am Base" << endl;
	}
	char *strf;
};

class Derived:public Base{
public:
	Derived(){
		this->strd = "Derived";
	}

	~Derived(){}

	void print(){
		cout << this->strd << endl;
	}

	void Demod(){
		cout << "I am Derived" << endl;
	}
	char *strd;
};
int main(void)
{
	//父类对象指向父类方法
	Base base1;
	base1.print();  //Base
	base1.Demof();	//I am Base
	Base *base2 = new Base;
	base2->print(); //Base
	base2->Demof(); //I am Base

	cout << "---------------------" << endl;
	//子类对象指向子类方法
	//子类覆盖父类同名的方法
	Derived derived1;
	derived1.Derived::print();   //Derived
	derived1.Demod();	//I am Derived
	Derived *derived2 = new Derived;
	derived2->print(); //Derived
	derived2->Demod(); //I am Derived

	cout << "---------------------" << endl;
	//父类对象指向子类方法
	Base *pb = new Derived;
	pb->print();	//Base
	pb->Demof();    //I am Base

	cout << "---------------------" << endl;
	//子类对象指向父类方法
	//直接转化错误Derived *pb = new Base;
	Base* pb2 = new Base;
	//static_cast主要用到虚函数对象之间转换
	Derived* pd = static_cast<Derived*>(pb2); //子类和父类对象之间转换用到
	pd->Base::print();  //不可写为pd->print(); 在父类中此处内存为空会报错	
	pd->Derived::Demof();   //I am Base  等价于pd->Demof();
	pd->Demod();     //I am Base
	//cout<<pd->strd << endl;  //错误 直接调用 引用了内部变量的函数
	system("pause");
}