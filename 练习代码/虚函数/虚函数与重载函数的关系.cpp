/*�����麯��ʱ������Ϊ�������Ͳ�ͬ �������ͬ�򱨴�
��������������ͬ,�������� ���� �������Ͳ�ͬ�������ͬ ����Ϊ��ͨ�������� �麯�����Զ�ʧ*/
#include<iostream>
using namespace  std;
class Base{
public:
    virtual void func1();
    virtual void func2();
    virtual void func3();
    void func4();
};
class Derived:public Base{
public:
    virtual void func1();//���麯�� virtual����ʡȥ
    void func2(int x);//������е�func2��Ϊ��ͨ�������� �����Զ�ʧ
    //char func3();������е�func3ֻ�з������Ͳ�ͬ Ӧɾȥ
    void func4();
};
void Base::func1()
{
    cout<<"---Base func1---"<<endl;
}
void Base::func2()
{
    cout<<"---Base func2---"<<endl;
}
void Base::func3()
{
    cout<<"---Base func3---"<<endl;
}
void Base::func4()
{
    cout<<"---Base func4---"<<endl;
}
void Derived::func1()
{
    cout<<"---Derived func1---"<<endl;
}
void Derived::func2(int x)
{
    cout<<"---Derived func2---"<<endl;
}
void Derived::func4()
{
    cout<<"---Derived func4---"<<endl;
}
int main()
{
    Base b1,*bp;
    Derived d1;
    bp = &d1;
    bp->func1();//����Derived::func1
    bp->func2();//����Base::func2
    bp->func4();//����Base::func4
    return 0;
}