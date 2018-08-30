//const修饰的引用为常引用,不会产生对实参的不希望的更改
//常引用做形参，能够避免对实参的更改
#include <iostream>
#include<cstring>
using namespace std;
int add(const int &a,const int &b);
int main()
{
    int a = 10;
    int b = 20;
    cout<<"a+b="<<add(a,b)<<endl;
}
int add(const int &a,const int &b)
{
    //i=i+20; //不允许改变i的值 否则出错
    return a+b;
}