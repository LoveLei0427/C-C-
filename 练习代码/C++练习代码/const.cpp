#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	int x;
	int y;
	//mutable声明的是不受const约束的类成员,在被const修饰的函数里面也能被修改
	//只能够用于一个类的非静态数据成员
	mutable int z;
	Demo() :x(10), y(20){}
	void printXY()const{
		cout << "x = " << x << endl;
		cout << "y = " << y <<endl;
		z += 1;
	}
	void add(int a){
		x += a;
		y += a;
	}

};
int main(void)
{
	//const限制对象是常量不可改变
	const Demo demo1;
	demo1.printXY(); //x=10 y=20
	//demo1.add(1); 错误  const对象不能引用非const成员函数

	Demo demo2;
	demo2.printXY(); //x=10 y =20 非const对象可以引用const成员函数
	//demo2printXY();错误 非const对象不能引用const成员函数 
	//demo2.add(1);

	system("pause");
}