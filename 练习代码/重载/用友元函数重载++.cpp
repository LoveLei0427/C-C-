/*ǰ׺��׺��ʽ�ĺ����ڲ�������ͬҲ���Բ�ͬ*/
#include<iostream>
using namespace std;
class Three{
public:
    friend Three operator++(Three &);
    friend Three operator++(Three &,int);
    Three(int i = 0,int j = 0,int k = 0);
    void print();
private:
    int a,b,c;
};
void Three::print()
{
     cout<<"a : "<<a<<" "<<"b : "<<b<<" "<<"c : "<<c<<endl;
}

Three::Three(int i, int j,int k)
{
    a = i;
    b = j;
    c = k;
}
Three operator++(Three &op1)//ǰ׺��ʽ
{
    ++op1.a;
    ++op1.b;
    ++op1.c;
    return op1;
}

Three operator++(Three &op1,int i)//��׺��ʽ
{
    (op1.a++)+i;
    op1.b++;
    op1.c++;
    return op1;  //���ǳ�Ա���������򷵻ص���thisָ�� ��Ϊ��Ԫ����û��thisָ�� ���Է��ص��Ƕ���
}
int main()
{
    Three obj1(10,20,30),obj2(60,70,80);
    obj1.print();
    ++obj1;//��ʽ����ǰ׺��ʽ
    obj1.print();//11 21 31
    obj1++;//��ʽ���ú�׺��ʽ
    obj1.print();//12 22 32
    cout<<endl;
    obj2.print();
    operator++(obj2);//��ʽ����ǰ׺��ʽ
    obj2.print();//61 71 81
    operator++(obj2,0);//��ʽ���ú�׺��ʽ
    obj2.print();//62 72 82
    return 0;
}