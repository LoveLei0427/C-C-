#include<iostream>
using namespace std;
class Complex{
public:
    void print();
    Complex(int i = 0,int j = 0);
    friend Complex operator+(Complex com,int a);
private:
    int real,imag;
};

Complex::Complex(int i, int j):real(i),imag(j){}
void Complex::print()
{
    cout<<"Real = "<<real<<"    Imag = "<<imag<<endl;
}
Complex operator+(Complex com,int a)
{
    return Complex(com.real+a,com.imag);
}
int main()
{
    Complex com1(30,40),com2;
    com2 = com1 + 30;
    com2.print();
    return 0;
}
