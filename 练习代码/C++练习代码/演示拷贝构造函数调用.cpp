#include<iostream>
using namespace std;
class Point	{
public:
	Point (int a0,int b=0);			//声明构造函数
	Point (const Point &p);			//声明拷贝构造函数
	void print()
	{
		cout<<x<<" "<<y<<endl;
	}
private:
	int x,y;
};
Point::Point(int a,int b)				//类外定义构造函数
{
	x=a;
	y=b;
	cout<<"Using normal constructor\n";
}
Point::Point(const Point &p)			//类外定义拷贝构造函数
{
	x=2*p.x;
	y=2*p.y;
	cout<<"Using copy constructor\n";

}
void fun1(Point p)						//函数fun1的形参是类对象
{
	p.print();
}
Point fun2()							//函数fun2的返回值是类对象
{
	Point p4(10,30);					//定义对象p4，调用普通构造函数
	return p4;							//调用拷贝构造函数
}
int main()
{
	Point p1(30,40);					//定义p1时，第一次调用普通构造函数
	p1.print();
	Point p2(p1);						//建立p2时，第一次调用拷贝构造函数
										//对象p1初始化对象p2
	p2.print();
	Point p3=p1;						//建立p3时，第二次调用拷贝构造函数
										//对象p1初始化对象p3
	p3.print();
	fun1(p1);							//调用函数fun1时，实参与形参结合时，第三次调用拷贝构造函数
	
	p2=fun2();							//调用fun2时，第二次调用普通的构造函数
										//调用fun2结束时，第四次调用拷贝构造函数

	p2.print();							
	return 0;
}