/*成员函数的两种调用方法是等价的 
1.对双目运算符而言 aa@bb等价于aa.operator(bb)
2.对单目运算符而言 @aa等价于aa.operator@()
*/
#include<iostream>
using namespace std;
class Complex{
public:
    Complex(double r = 0,double i = 0);
    void print();
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
private:
    double real;
    double imag;
};
Complex::Complex(double r, double i):real(r),imag(i)
{
//    real = r;
//    imag = i;
}
void Complex::print()
{
    cout<<real;
    if(imag>0)cout<<"+";
    if(imag!=0)cout<<imag<<"i"<<endl;
}
Complex Complex::operator+(Complex c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-(Complex c)
{
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;
    return temp;
}
Complex Complex::operator*(Complex c)
{
    Complex temp;
    temp.real = real * c.real - imag * c.imag;
    temp.imag = real * c.imag + imag * c.real;
    return temp;
}
Complex Complex::operator/(Complex c)
{
    Complex temp;
    double t;
    t = 1/(c.real * c.real + c.imag * c.imag);
    temp.real = (real * c.real + imag * c.imag)*t;
    temp.imag = (c.real * imag - real * c.imag)*t;
    return temp;
}
int main()
{
    Complex A1(2.3,4.6),A2(3.6,2.8),A3,A4,A5,A6;
    A3 = A1.operator +(A2);//等价于A3=A1+A2
    A4 = A1.operator -(A2);
    A5 = A1.operator *(A2);
    A6 = A1.operator /(A2);
    A1.print();
    A2.print();
    A3.print();
    A4.print();
    A5.print();
    A6.print();
    return 0;
}