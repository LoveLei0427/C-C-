//��̬�Լ��������� ���κ�Բ�����
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
    {/*�ڻ����ж�����麯��Ϊ�������ṩһ�������ӿ� �Ա������������Ҫ���¶���*/}
protected:
    double x,y;
};
class Triangle:public Figure{
public:
    Triangle(double a,double b):Figure(a,b){}
    void area(){
        cout<<"�����εĸ���:"<<x<<"����:"<<y;
        cout<<"�����:"<<0.5 * x * y<<endl;
    }
};
class Square:public Figure{
public:
    Square(double a,double b):Figure(a,b){}
    void area(){
        cout<<"���εĳ���:"<<x<<"����:"<<y;
        cout<<"�����:"<<x * y<<endl;
    }
};
class Circle:public Figure{
public:
    Circle(double a):Figure(a,a){}
    void area(){
        cout<<"Բ�İ뾶��:"<<x;
        cout<<"Բ�������:"<<PI * x  * x<<endl;
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