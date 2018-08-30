/*友元函数的两种调用方法是等价的 
1.对双目运算符而言 aa@bb等价于operator(aa,bb)
2.对单目运算符而言 @aa等价于operator@(aa)
*/
#include<iostream>
using namespace std;
class Complex{
public:
    void print();
    Complex (int i = 0,int j = 0);
    friend Complex operator++(Complex &obj);
private:
    int x;
    int y;
};
Complex::Complex (int i,int j)
{
    x = i;
    y = j;
}
Complex operator++(Complex &obj)
{
    ++obj.x;
    ++obj.y;
    return obj;
}
void Complex::print()
{
    cout<<"x :"<<x<<endl;
    cout<<"y :"<<y<<endl;
}
int main()
{
    Complex ob(10,20);
    ob.print();
    operator++(ob);//显式调用
    ob.print();
    ++ob;//隐式调用
    ob.print();
    return 0;
}