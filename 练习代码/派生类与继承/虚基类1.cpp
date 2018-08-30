/*虚基类在派生类中声明语法如下:
class 派生类名:virtual 继承方式 基类名{}
当基类通过多条派生路径被一个派生类继承时,该派生类只继承一次,即基类成员只保留一次
输出结果:
Base a = 5
Base1 a = 15
Base2 a = 35
Derived a = 5
*/
#include<iostream>
using namespace std;
class Base{
public:
    Base()
    {
        a = 5;
        cout<<"Base a = "<<a<<endl;
    }
protected:
    int a;
};

class Base1:virtual public Base{
public:
    Base1()
    {
        a = a + 10;
        cout<<"Base1 a = "<<a<<endl;
    }
};

class Base2:virtual public Base{
public:
    Base2()
    {
        a = a + 20;
        cout<<"Base2 a = "<<a<<endl;
    }
};

class Derived:public Base1,public Base2{
public:
    Derived()
    {
         cout<<"Derived a = "<<a<<endl;
    }
};

int main()
{
    Derived obj;
    return 0;
}