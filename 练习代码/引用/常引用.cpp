//const���ε�����Ϊ������,���������ʵ�εĲ�ϣ���ĸ���
//���������βΣ��ܹ������ʵ�εĸ���
#include <iostream>
#include<cstring>
using namespace std;
int add(const int &a,const int &b);
int main()
{
    int a = 10;
    int b = 20;
    cout<<"a+b="<<add(a,b)<<endl;
}
int add(const int &a,const int &b)
{
    //i=i+20; //������ı�i��ֵ �������
    return a+b;
}