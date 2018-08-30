/*主函数中用new建立派生类的无名对象和基类的对象指针,并将无名对象的地址赋给对象那个指针则撤销这个对象时只执行基类的析构函数
原因是采用了静态联编的方式*/
#include<iostream>
using namespace  std;
class A{
public:
    ~A()
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