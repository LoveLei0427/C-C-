/*重载虚函数时仅仅因为返回类型不同 其余均不同则报错
若仅仅函数名相同,参数个数 类型 返回类型不同其余均相同 则作为普通函数重载 虚函数特性丢失*/
#include<iostream>
using namespace  std;
class Base{
public:
    virtual void func1();
    virtual void func2();
    virtual void func3();
    void func4();
};
class Derived:public Base{
public:
    virtual void func1();//是虚函数 virtual可以省去
    void func2(int x);//与基类中的func2作为普通函数重载 虚特性丢失
    //char func3();与基类中的func3只有返回类型不同 应删去
    void func4();
};
void Base::func1()
{
    cout<<"---Base func1---"<<endl;
}
void Base::func2()
{
    cout<<"---Base func2---"<<endl;
}
void Base::func3()
{
    cout<<"---Base func3---"<<endl;
}
void Base::func4()
{
    cout<<"---Base func4---"<<endl;
}
void Derived::func1()
{
    cout<<"---Derived func1---"<<endl;
}
void Derived::func2(int x)
{
    cout<<"---Derived func2---"<<endl;
}
void Derived::func4()
{
    cout<<"---Derived func4---"<<endl;
}
int main()
{
    Base b1,*bp;
    Derived d1;
    bp = &d1;
    bp->func1();//调用Derived::func1
    bp->func2();//调用Base::func2
    bp->func4();//调用Base::func4
    return 0;
}