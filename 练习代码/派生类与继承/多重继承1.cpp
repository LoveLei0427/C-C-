//���ؼ̳�
#include<iostream>
using namespace std;
class A{
public:
    void setx(int x)
    {
        a = x;
    }
    void showx()
    {
        cout<<"a = "<<a<<endl;
    }
private:
    int a;
};
class B{
public:
    void sety(int x)
    {
        b = x;
    }
    void showy()
    {
        cout<<"b = "<<b<<endl;
    }
private:
    int b;
};
class C : public A,private B{
public:
    void setz(int x,int y)
    {
        c = x;
        sety(y);
    }
    void showz()
    {
        showy();
        cout<<"z = "<<c<<endl;
    }
private:
    int c;
};

int main()
{
    C obj;
    obj.setx(1);
    obj.showx();
    /*
    obj.sety(2);
    obj.showy();
    �˳�Ա������Z���ѳ�Ϊ˽�г�Ա
    */
    obj.setz(3,4);
    obj.showz();
    return 0;
}