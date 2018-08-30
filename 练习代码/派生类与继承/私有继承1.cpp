#include <iostream>
using namespace std;
class Base{
public:
    void setx(int n)
    {
        x = n;
    }
    void showx()
    {
        cout<<x<<endl;
    }
private:
    int x;
};
//声明基类Base的私有派生类Derived
class Derived:private Base
{
public:
    void setxy(int n,int m)
    {
        setx(n);
        //基类的函数在派生类中为私有成员,派生类的成员函数可以访问
        y = m;
    }
    void showxy()
    {
        //cout<<x<<endl;错误,派生类成员函数不能直接访问基类的私有成员
        showx();
        cout<<y<<endl;
    }
private:
    int y;
};
int main()
{
    Derived obj;
    /*这两个函数在派生类中为私有成员,派生类对象不能访问
    obj.setx(9);
    obj.showx();
     */
    obj.setxy(10,20);
    obj.showxy();
    return 0;
}
