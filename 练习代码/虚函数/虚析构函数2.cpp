/*ϣ��������ö�̬����ķ�ʽ���������������������ʱ�ȵ�������������������ٵ��û������������
 *  ���Խ������������������Ϊ����������*/
#include<iostream>
using namespace  std;
class A{
public:
    virtual ~A()
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