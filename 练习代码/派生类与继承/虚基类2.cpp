/*Base������࣬�Һ��д������Ĺ��캯��,������������б��뺬�жԻ���ĵ���
*/
#include<iostream>
using namespace std;
class Base{
public:
    Base(int a1)
    {
        a = a1;
        cout<<"Constructing Base"<<endl;
    }
protected:
    int a;
};

class Base1:virtual public Base{
public:
    Base1(int a1,int b1):Base(a1)//�ڴ˱���׺�϶�Base�๹�캯���ĵ���
    {
        b = b1;
        cout<<"Constructing Base1"<<endl;
    }
private:
    int b;
};

class Base2:virtual public Base{
public:
    Base2(int a1,int c1):Base(a1)//�ڴ˱���׺�϶�Base�๹�캯���ĵ���
    {
        c = c1;
        cout<<"Constructing Base2"<<endl;
    }
private:
    int c;
};

class Derived:public Base1,public Base2{
public:
    //�ڴ˱���׺�϶�Base�๹�캯���ĵ���
    Derived(int a1,int b1,int c1,int d1):Base(a1),Base1(a1,b1),Base2(a1,c1)
    {
         d = d1;
         cout<<"Constructing Derived"<<endl;
    }
private:
    int d;
};

int main()
{
    Derived obj(1,2,3,4);
    return 0;
}