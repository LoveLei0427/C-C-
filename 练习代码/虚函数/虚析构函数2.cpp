/*希望程序采用动态联编的方式即撤销派生类的无名对象时先调用派生类的析构函数再调用基类的析构函数
 *  可以将基类的析构函数声明为虚析构函数*/
#include<iostream>
using namespace  std;
class A{
public:
    virtual ~A()
    {
        cout<<"A's Destruction!\n";
    }
};
class B:public A{
public:
    ~B()
    {
        cout<<"B's Destruction!\n";
    }
};

int main()
{
    A *p;
    p = new B;
    delete p;
    return 0;
}