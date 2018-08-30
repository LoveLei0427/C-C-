//双目运算符重载
#include <iostream>
using namespace std;

class Complex{
public:
    Complex(double r = 0,double i = 0);
    void print();
    friend Complex operator+(Complex &a,Complex &b);
    friend Complex operator-(Complex &a,Complex &b);
    friend Complex operator*(Complex &a,Complex &b);
    friend Complex operator/(Complex &a,Complex &b);
private:
    double real;
    double imag;
};
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

Complex operator+(Complex &a,Complex &b)
{
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
    //return temp可以改为return Complex(a.real+b.real,a.imag+b.imag)；建立临时对象 没有对象名 效率高但是可读性较前一种低
}

Complex operator-(Complex &a,Complex &b)
{
    Complex temp;
    temp.real = a.real - b.real;
    temp.imag = a.imag - b.imag;
    return temp;
}

Complex operator*(Complex &a,Complex &b)
{
    Complex temp;
    temp.real = a.real * b.real - a.imag * b.imag;
    temp.imag = a.real * b.imag + a.imag * b.real;
    return temp;
}

Complex operator/(Complex &a,Complex &b)
{
    Complex temp;
    double t;
    t = 1/(b.real * b.real + b.imag * b.imag);
    temp.real = t * (a.real * b.real + a.imag * b.imag);
    temp.imag = t * (a.imag * b.real - a.real * b.imag);
    return temp;
}

void Complex::print()
{
    cout<<real;
    if(imag>0)
        cout<<"+";
    else cout<<"-";
    if(imag!=0)cout<<imag<<"i"<<endl;
}
int main()
{
    Complex A1(2.3,4.6),A2(3.6,2.8),A3,A4,A5,A6;
    A3 = A1 + A2;
    A4 = A1 - A2;
    A5 = A1 * A2;
    A6 = A1 / A2;
    A1.print();
    A2.print();
    A3.print();
    A4.print();
    A5.print();
    A6.print();
    return 0;
}