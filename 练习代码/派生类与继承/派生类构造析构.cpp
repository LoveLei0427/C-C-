//构造函数:先基类后派生类;析构函数:先派生后基类;
#include<iostream>
using namespace std;
class Base{
public:
    Base()
    {
        cout<<"Constructing Base Class!"<<endl;
    }
    ~Base()
    {
        cout<<"Destructing Base Class!"<<endl;
    }
};
class Derived:public Base{
public:
    Derived()
    {
        cout<<"Constructing Derived Class!"<<endl;
    }
    ~Derived()
    {
        cout<<"Destructing Derived Class!"<<endl;
    }
};
int main()
{
    Derived op;
    return 0;
}