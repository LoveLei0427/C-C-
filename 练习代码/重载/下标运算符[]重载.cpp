//�±����������[],ֻ�ܶ���Ϊ��Ա����
//����ֵ��һ��int���͵�����
#include<iostream>
#include<cstring>
using namespace  std;
class Vector{
public:
    Vector(int,int,int,int);
    int &operator[](int);
private:
    int v[4];
};
Vector::Vector(int a, int b, int c, int d)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
}
int &Vector::operator [](int i)
{
    if(i<0||i>3)
    {
        cout<<"ERROR"<<endl;
        exit(1);
    }
    return v[i];
}
int main()
{
    Vector v(1,2,3,4);
    cout<<v.operator [](2)<<endl;//v[2]�ȼ�,��Ϊ������ɺ�main��������ֱ�ӷ���˽�����ݳ�Ա��
    v[0] = v[1];
    cout<<v[0]<<endl;//v[0]��������v.operator[](0)
    return 0;
}