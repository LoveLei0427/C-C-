/*基类与派生类之间对象赋值兼容关系
指的是在需要基类对象的任何地方都能够使用共有派生类的对象来替代
注意:1.声明为指向基类对象的指针可以指向它的公有派生的对象,不允许指向私有派生对象
    2.允许将一个声明为指向基类的指针指向公有派生类的对象,但是不能将一个声明为指向派生类对象的指针指向其基类的对象*/
#include<iostream>
using namespace std;
class Base{
public:
    int i;
    Base(int x)
    {
        i = x;
    }
    void show()
    {
        cout<<"Base "<<i<<endl;
    }
};

class Derived:public Base{
public:
    Derived(int x):Base(x){}
};
//形参为基类对象的引用输出该引用所代表的对象的数据成员i
void fun(Base &bb)
{
    cout<<bb.i<<endl;
}

int main()
{
    Base b1(100);
    b1.show();
    Derived d1(11);
    b1 = d1;//派生类对象给基类对象赋值(逐个赋值)
    b1.show();
    Derived d2(22);
    Base b2 = &d2;//派生类初始基类对象的引用
    b2.show();
    Derived d3(33);
    Base *b3 = &d3;//派生类对象的地址&d3赋值给指向基类的指针b3
    b3->show();
    Derived d4(44);
    fun(d4);
    return 0;
}