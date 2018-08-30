//多态性计算三角形 矩形和圆的面积
#include<iostream>
using namespace std;
#define PI 3.1415
class Figure{
public:
    Figure(double a,double b)
    {
        x = a;
        y = b;
    }
    virtual void area()
    {/*在基类中定义的虚函数为派生类提供一个公共接口 以便派生类根据需要重新定义*/}
protected:
    double x,y;
};
class Triangle:public Figure{
public:
    Triangle(double a,double b):Figure(a,b){}
    void area(){
        cout<<"三角形的高是:"<<x<<"底是:"<<y;
        cout<<"面积是:"<<0.5 * x * y<<endl;
    }
};
class Square:public Figure{
public:
    Square(double a,double b):Figure(a,b){}
    void area(){
        cout<<"矩形的长是:"<<x<<"宽是:"<<y;
        cout<<"面积是:"<<x * y<<endl;
    }
};
class Circle:public Figure{
public:
    Circle(double a):Figure(a,a){}
    void area(){
        cout<<"圆的半径是:"<<x;
        cout<<"圆的面积是:"<<PI * x  * x<<endl;
    }
};
int main()
{
    Figure *p;
    Triangle t(10,6);
    Square s(10,6);
    Circle c(10);
    p = &t;
    p->area();
    p = &s;
    p->area();
    p = &c;
    p->area();
    return 0;
}