#include<iostream>
#include<cmath>
using namespace std;
class Complex{
private:
    double real;
    double imag;
public:
    void init(double r,double i);
    double abscomplex();       //类内部声明成员函数
}op1,op2;//声明类的同时直接定义对象
    void Complex::init(double r, double i)//类外部定义成员函数
    {
        real = r;
        imag = i;
    }
    double Complex::abscomplex()
    {
        double t;
        t = real * real + imag * imag;
        return sqrt(t);
    }
int main()
{
    Complex A;//声明类之后定义对象
    A.init(1.1,2.2);
    op1.init(1.1,2.2);
    op2.init(1.1,2.2);
    cout<<A.abscomplex()<<endl;
    cout<<op1.abscomplex()<<endl;
    cout<<op2.abscomplex()<<endl;
    return 0;
}