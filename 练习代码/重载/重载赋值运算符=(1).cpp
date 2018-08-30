//对象之间可以直接用=赋值但是当一个类中包含指针类型的成员变量时,可能会带来问题.因此要重载
#include<iostream>
using namespace  std;
class Equal{
public:
    Equal & operator=(const Equal &ob);
    /*重载赋值函数
     * 也可以写成void operator(Equal&a)
     * 但是不返回任何值同时不支持链式赋值例如a=b=c*/
    void print();
    Equal(int i=0);
private:
    int x;
};
Equal::Equal(int i)
{
    x = i;
}

void Equal::print()
{
    cout<<x<<endl;
}

Equal & Equal::operator=(const Equal &ob)
{
    if(this!=&ob)//有无判断无所谓
    {
        this->x = ob.x;
    }
    return *this;
}

int main()
{
    Equal ob2(2);
    Equal ob1,ob3;
    ob2.print();
    ob1=ob2;//隐式调用
    ob1.print();
    ob3.operator=(ob2);//显式调用
    ob3.print();
    return 0;
}