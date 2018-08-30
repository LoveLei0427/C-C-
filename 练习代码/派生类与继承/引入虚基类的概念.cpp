#include<iostream>
using namespace std;

class Base{
public:
    Base()
    {
        a = 5;
        cout<<"Base a = "<<a<<endl;
    }
protected:
    int a;
};

class Base1:public Base{
public:
    Base1()
    {
       a = a + 10;
       cout<<"Base1 a = "<<a<<endl;
    }
};

class Base2:public Base{
public:
    Base2()
    {
       a = a + 20;
       cout<<"Base2 a = "<<a<<endl;
    }
};
/*在Base1和Base2中存在着同名的a,因此输出时必须加上"类名::"
 * 指出是哪一个数据成员a,否则就会出现二义性.即:
 * Derived(){cout<<"Derived a = "<<a;}
*/
class Derived:public Base1,public Base2{
public:
    Derived()
    {
        cout<<"Base1::a = "<<Base1::a<<endl;
        cout<<"Base2::a = "<<Base2::a<<endl;
    }
};

int main()
{
    Derived obj;
    return 0;
}