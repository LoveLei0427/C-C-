/*����������new�������������������ͻ���Ķ���ָ��,������������ĵ�ַ���������Ǹ�ָ�������������ʱִֻ�л������������
ԭ���ǲ����˾�̬����ķ�ʽ*/
#include<iostream>
using namespace  std;
class A{
public:
    ~A()
    {
        cout<<"A's Destruction!\n";
    }
};
class B:public A{
public:
    ~B()
    {
        cout<<"B's Destruction!\n";
    }
};

int main()
{
    A *p;
    p = new B;
    delete p;
    return 0;
}