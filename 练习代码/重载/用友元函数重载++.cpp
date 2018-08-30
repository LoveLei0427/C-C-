/*前缀后缀方式的函数内部可以相同也可以不同*/
#include<iostream>
using namespace std;
class Three{
public:
    friend Three operator++(Three &);
    friend Three operator++(Three &,int);
    Three(int i = 0,int j = 0,int k = 0);
    void print();
private:
    int a,b,c;
};
void Three::print()
{
     cout<<"a : "<<a<<" "<<"b : "<<b<<" "<<"c : "<<c<<endl;
}

Three::Three(int i, int j,int k)
{
    a = i;
    b = j;
    c = k;
}
Three operator++(Three &op1)//前缀方式
{
    ++op1.a;
    ++op1.b;
    ++op1.c;
    return op1;
}

Three operator++(Three &op1,int i)//后缀方式
{
    (op1.a++)+i;
    op1.b++;
    op1.c++;
    return op1;  //若是成员函数重载则返回的是this指针 因为友元函数没有this指针 所以返回的是对象
}
int main()
{
    Three obj1(10,20,30),obj2(60,70,80);
    obj1.print();
    ++obj1;//隐式调用前缀方式
    obj1.print();//11 21 31
    obj1++;//隐式调用后缀方式
    obj1.print();//12 22 32
    cout<<endl;
    obj2.print();
    operator++(obj2);//显式调用前缀方式
    obj2.print();//61 71 81
    operator++(obj2,0);//显式调用后缀方式
    obj2.print();//62 72 82
    return 0;
}