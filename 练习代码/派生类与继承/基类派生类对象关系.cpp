/*������������֮�����ֵ���ݹ�ϵ
ָ��������Ҫ���������κεط����ܹ�ʹ�ù���������Ķ��������
ע��:1.����Ϊָ���������ָ�����ָ�����Ĺ��������Ķ���,������ָ��˽����������
    2.����һ������Ϊָ������ָ��ָ����������Ķ���,���ǲ��ܽ�һ������Ϊָ������������ָ��ָ�������Ķ���*/
#include<iostream>
using namespace std;
class Base{
public:
    int i;
    Base(int x)
    {
        i = x;
    }
    void show()
    {
        cout<<"Base "<<i<<endl;
    }
};

class Derived:public Base{
public:
    Derived(int x):Base(x){}
};
//�β�Ϊ���������������������������Ķ�������ݳ�Աi
void fun(Base &bb)
{
    cout<<bb.i<<endl;
}

int main()
{
    Base b1(100);
    b1.show();
    Derived d1(11);
    b1 = d1;//�����������������ֵ(�����ֵ)
    b1.show();
    Derived d2(22);
    Base b2 = &d2;//�������ʼ������������
    b2.show();
    Derived d3(33);
    Base *b3 = &d3;//���������ĵ�ַ&d3��ֵ��ָ������ָ��b3
    b3->show();
    Derived d4(44);
    fun(d4);
    return 0;
}