/*不允许重载的运算符有 .  .*  ::  Sizeof  ?:
 * 重载不改变运算符的优先级 操作对象个数
 * 运算符重载函数的参数 至少有一个是类对象或其引用
 * 重载函数可以是普通函数 类的成员函数 友元函数
*/
#include <iostream>
using namespace std;
class Complex{
public:
    double real;
    double imag;
    Complex(double r = 0,double i = 0)
    {
        real = r;
        imag = i;
    }
};

Complex operator+ (Complex c1,Complex c2)
{
    Complex temp;
    temp.real=c1.real + c2.real;
    temp.imag=c1.imag + c2.imag;
    return temp;
}

int main()
{
    Complex com1(1.1,2.2),com2(3.3,-4.4),total1,total2;
    total1=operator+(com1,com2);
    //调用运算符重载函数的第一种方式
    cout<<"Real1 = "<<total1.real<<" "<<"Imag1 = "<<total1.imag<<endl;
    //调用运算符重载函数的第二种方式
    total2 = com1 + com2;
    cout<<"Real2 = "<<total2.real<<" "<<"Imag2 = "<<total2.imag<<endl;
    return 0;
}