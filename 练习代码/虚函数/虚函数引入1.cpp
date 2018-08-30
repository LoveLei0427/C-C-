#include<iostream>
using namespace  std;
class base{
public:
    base(int a,int b)
    {
        x = a;
        y = b;
    }
    void show()
    {
        cout<<"Base's show:\n";
        cout<<x<<" "<<y<<endl;
    }
private:
    int x;
    int y;
};
class der:public base{
public:
    der(int a,int b,int c):base(a,b)
    {
        z = c;
    }
    void show()
    {
        cout<<"Der's show:\n";
        cout<<"z="<<z<<endl;
    }
private:
    int z;
};
int main()
{
    base mb(10,20),*mp;
    der mc(11,22,33);
    mp = &mb;
    mp->show();
    mp = &mc;
    /*虽然指针指向派生类的对象 但是调用的仍然是基类的同名成员函数
      因为基类的对象指针可以指向公有派生的对象 但是当其指向公有派生类对象时
      只能访问派生类中从基类中继承来的成员而不是公有派生类中定义的成员*/
    mp->show();
    return 0;
}
/*
输出结果为:Base's show:
          10 20
          Der's show:
          11 22*/