/*多重继承下的派生类和基类的构造函数时和析构函数的执行顺序:
*/
#include<iostream>
using namespace std;

class X{
public:
    X(int x)
    {
        a = x;
    }
    int getX()
    {
        return a;
    }
    ~X()
    {
        cout<<"X_Destructor."<<endl;
    }
private:
    int a;
};

class Y{
public:
    Y(int y)
    {
        b = y;
    }
    int getY()
    {
        return b;
    }
    ~Y()
    {
        cout<<"Y_Destructor."<<endl;
    }
private:
    int b;
};

class Z:public X,private Y{
public:
    Z(int x,int y,int z):X(x),Y(y)
    {
        c = z;
    }
    int getZ()
    {
        return c;
    }
    /*Y中构造函数已为私有在main中不能直接引用*/
    int getY()
    {
        return Y::getY();
    }
    ~Z()
    {
        cout<<"Z_Destructor."<<endl;
    }
private:
    int c;
};

int main()
{
    Z obj(1,2,3);
    int a1 = obj.getX();
    cout<<"a = "<<a1<<endl;
    int b1 = obj.getY();
    cout<<"b = "<<b1<<endl;
    int z1 = obj.getZ();
    cout<<"c = "<<z1<<endl;
    return 0;
}