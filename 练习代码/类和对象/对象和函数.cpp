#include<iostream>
#include<cmath>
using namespace std;
class Complex{
private:
    double real;
    double imag;
public:
    void init(double r,double i);
    double abscomplex();       //���ڲ�������Ա����
}op1,op2;//�������ͬʱֱ�Ӷ������
    void Complex::init(double r, double i)//���ⲿ�����Ա����
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
    Complex A;//������֮�������
    A.init(1.1,2.2);
    op1.init(1.1,2.2);
    op2.init(1.1,2.2);
    cout<<A.abscomplex()<<endl;
    cout<<op1.abscomplex()<<endl;
    cout<<op2.abscomplex()<<endl;
    return 0;
}