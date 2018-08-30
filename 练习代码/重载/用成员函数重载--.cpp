补充/*
a=5     (1)int b = a--;  b=5,a=4
        (2)a--;          a=4
        (3)int b = --a;  b=4,a=4
        (4)--a;          a=4 

a=5	(1)int b = a++;  b=5,a=6
        (2)a++;          a=6
        (3)int b = ++a;  b=6,a=6
        (4)++a;          a=6 

*/







//成员函数以前缀和后缀方式重载运算符--
#include<iostream>
using namespace std;
class Three{
public:
    void print();
    Three(int i = 0,int j = 0,int k = 0);
    Three operator--();
    Three operator--(int);
private:
    int a;
    int b;
    int c;
};
Three::Three(int i, int j, int k)
{
    a = i;
    b = j;
    c = k;
}
Three Three::operator --()//定义重载函数--前缀方式 先自减 返回的是修改后的对象本身
{
    --a;
    --b;
    --c;
    return *this;//返回自减后的当前对象
}
Three Three::operator --(int)//定义重载函数--后缀方式 返回的是自减前的对象 然后对其自减 (int)只是为了he前缀做区分
{
    Three temp(*this);
    a--;
    b--;
    c--;
    return temp;

}
void Three::print()
{
    cout<<"a : "<<a<<" "<<"b :"<<b<<" "<<"c :"<<c<<endl;
}
int main()
{
    Three th1(20,60,80),th2,th3(30,50,70),th4;
    th1.print();
    --th1;      //隐式调用Three operator--()
    th1.print();//输出--th1后的th1值:19 59 79
    th2 = th1--;//将th1自减以前的值赋给th2
    th2.print();//输出th2保存的对象th1的值19 59 79
    th1.print();//输出执行th1--后的th1的值:18 58 78
    cout<<"*******************"<<endl;
    th3.print();          //30,50,70
    th3.operator --();//显式调用意为--th3
    th3.print();       //输出--th3以后th3的值 29,49,69
    th4 = th3.operator --(0);//将th3自减以前的值赋给th4(29,49,69) th3变为(28,48,68)
    th4.print();        //th4保存的是执行th3--前th3的值
    th3.print();        //输出执行th3--后th3的值
    return 0;
}