/*
1、派生类中虚函数被重新定义时,函数原型与基类中完全相同
2、虚函数是成员函数 不能是友元函数或静态成员函数
3、使用对象名.调用虚函数是静态联编方式没有用到虚函数特性 只有通过基类指针访问虚函数才能获得运行时多态
4、虚函数占用四个字节 本质是函数指针
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(int x){ a = x;}
	//若只在类内声明 则类外定义时不需再加virtual
	virtual void show(){ cout << "Base a=" << a << endl; }
protected:
	int a;
};

class Derived1:public Base{
public:
	Derived1(int x,int y):Base(x){
		b = y;
	}
	virtual void show(){ cout << "Derived1 b=" << b <<endl; }
protected:
	int b;
};

class Derived2 :public Derived1{
public:
	Derived2(int x, int y,int z):Derived1(x,y){ 
		c = z;
	}
	virtual void show(){ cout << "Derived2 c=" << c <<endl; }
protected:
	int c;
};
int main(void)
{
	Base b(1);
	Derived1 d1(2, 3);
	Derived2 d2(4,5,6 );
	Base* b1;
	b1 = &b;
	b1->show(); //Base a=1
	b1 = &d1;
	b1->show();  //Derived1 b=3
	b1 = &d2;
	b1->show();  //Derived2 c=6
	
	d1.show();   //Derived1 b=3 
	d2.show();	//Derived2 c=6
	((Derived2*)b1)->show(); //Derived2 c=6

	system("pause");
}