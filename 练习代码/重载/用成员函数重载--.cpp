����/*
a=5     (1)int b = a--;  b=5,a=4
        (2)a--;          a=4
        (3)int b = --a;  b=4,a=4
        (4)--a;          a=4 

a=5	(1)int b = a++;  b=5,a=6
        (2)a++;          a=6
        (3)int b = ++a;  b=6,a=6
        (4)++a;          a=6 

*/







//��Ա������ǰ׺�ͺ�׺��ʽ���������--
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
Three Three::operator --()//�������غ���--ǰ׺��ʽ ���Լ� ���ص����޸ĺ�Ķ�����
{
    --a;
    --b;
    --c;
    return *this;//�����Լ���ĵ�ǰ����
}
Three Three::operator --(int)//�������غ���--��׺��ʽ ���ص����Լ�ǰ�Ķ��� Ȼ������Լ� (int)ֻ��Ϊ��heǰ׺������
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
    --th1;      //��ʽ����Three operator--()
    th1.print();//���--th1���th1ֵ:19 59 79
    th2 = th1--;//��th1�Լ���ǰ��ֵ����th2
    th2.print();//���th2����Ķ���th1��ֵ19 59 79
    th1.print();//���ִ��th1--���th1��ֵ:18 58 78
    cout<<"*******************"<<endl;
    th3.print();          //30,50,70
    th3.operator --();//��ʽ������Ϊ--th3
    th3.print();       //���--th3�Ժ�th3��ֵ 29,49,69
    th4 = th3.operator --(0);//��th3�Լ���ǰ��ֵ����th4(29,49,69) th3��Ϊ(28,48,68)
    th4.print();        //th4�������ִ��th3--ǰth3��ֵ
    th3.print();        //���ִ��th3--��th3��ֵ
    return 0;
}