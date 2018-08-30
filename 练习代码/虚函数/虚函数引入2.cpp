/*声明为虚函数后virtual就能指示编译器,根据指针指示的实际对象,调用该对象的成员函数(动态联编)
虚函数的定义  virtual 函数类型 函数名称(参数表){} 若在基类中只声明虚函数原型 在类外定义时不用再加virtual
虚函数必须是成员函数 不能是友元函数 或者是静态成员函数
基类中的成员函数被声明为虚函数后可以在多个派生类中重新定义
 但是类型 函数名 参数个数 参数类型需要与原函数相同
*/
#include<iostream>
using namespace  std;
class Base{
public:
    Base(int a,int b)
    {
        x = a;
        y = b;
    }
    virtual void show()    {
        cout<<"Base's Show:\n";
        cout<<x<<" "<<y<<endl;
    }
private:
    int x,y;
};
class Derived:public Base{
public:
    Derived(int a,int b,int c):Base(a,b)
    {
        z = c;
    }
    virtual void show()//派生类中重新定义虚函数
    {
        cout<<"Derived's Show:\n";
        cout<<z<<endl;
    }
private:
    int z;
};
int main()
{
    Base ma(10,20),*op;
    Derived mb(11,22,33);
    op = &ma;
    op->show();
    op = &mb;
    op->show();
    return 0;
}
/*运行结果:Base's Show:
          10 20
          Derived's Show:
          33*/