//具有纯虚函数的基类成为抽象类 
//纯虚函数只在本类声明 限制类进行实例化(抽象类无法实例化对象但可以实例化指针)
//抽象类不可以用于函数的参数以及返回值类型 抽象类指针可以
/*Base *test(Base* p)
{Base* pbase(nullptr);return pbase;}*/
//应用抽行类 求圆及圆内接正方形、外切正方形的面积和周长
#include<iostream>
#include<stdlib.h>
using namespace std;
#define PI 3.14
//声明抽象类
class Shape{
public:
	virtual void Area() = 0;
	virtual void Perimeter() = 0;
	Shape(double x){ r = x; }
protected:
	double r;
};
//声明圆派生类
class Circle :public Shape{
public:
	Circle(double x) :Shape(x){}
	void Area(){
		cout << "圆的面积是" <<PI * r * r<< endl;
	}
	void Perimeter(){
		cout << "圆的周长是" << 2 * PI * r << endl;
	}
};
//声明圆内接正方形类
class In_square :public Shape{
public:
	In_square(double x) :Shape(x){}
	void Area(){
		cout << "内接正方形的面积是" << 2 * r * r << endl;
	}
	void Perimeter(){
		cout << "内接正方形的周长是" << 4 * 1.414 * r << endl;
	}
};
//声明圆外切正方形类
class Ex_square :public Shape{
public:
	Ex_square(double x) :Shape(x){}
	void Area(){
		cout << "外切方形的面积是" << 4 * r * r << endl;
	}
	void Perimeter(){
		cout << "外切正方形的周长是" << 8 * r << endl;
	}
};
int main(void)
{
	Shape* ptr;
	Circle cir(5.0);
	ptr = &cir;
	ptr->Area();
	ptr->Perimeter();

	In_square in_squ(5.0);
	ptr = &in_squ;
	ptr->Area();
	ptr->Perimeter();

	Ex_square ex_squ(5.0);
	ptr = &ex_squ;
	ptr->Area();
	ptr->Perimeter();

	system("pause");
}