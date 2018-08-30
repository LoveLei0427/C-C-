#include<iostream>
using namespace std;
class Base
{
public:
    int z;
    void setx(int i)
    {
        x = i;
    }
    int getx()
    {
        return x;
    }
private:
    int x;
protected:
    int y;
};
class Derived:protected Base{
    public:
    int p;
    void setall(int a,int b,int c,int d,int e,int f);
    void show();
private:
    int m;
protected:
    int n;
};
void Derived::setall(int a,int b,int c,int d,int e,int f)
{
    setx(a);
    y = b;
    z = c;
    m = d;
    n = e;
    p = f;
}
void Derived::show()
{
    cout<<"x = "<<getx()<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;
    cout<<"m = "<<m<<endl;
    cout<<"n = "<<n<<endl;
}
int main()
{
    Derived op1;
    op1.setall(1,2,3,4,5,6);
    op1.show();
    cout<<"p = "<<op1.p<<endl;
    return 0;
}