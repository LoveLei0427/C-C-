#include <iostream>
using namespace std;
class Base{
public:
    void setx(int n)
    {
        x = n;
    }
    void showx()
    {
        cout<<"Base:"<<endl;
        cout<<x<<endl;
    }
protected:
    int x;
};
class Derive1:private Base
{
public:
    void setxy(int n,int m)
    {
        x = n;//x����������Ϊ˽�г�Ա,�������Ա�������Է���
        y = m;
    }
    void showxy()
    {
        cout<<"Derive1:"<<endl;
        //x����������Ϊ˽�г�Ա,�������Ա�������Է���
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }
protected:
    int y;
};
class Derive2:private Derive1{
public:
    void setxyz(int n,int m,int r)
    {
        setxy(n,m);
        z = r;
    }
    void showxyz()
    {
        cout<<"Derive2:"<<endl;
        //cout<<"x = "<<x<<endl;����x����Derive2��Ϊ����ֱ�ӷ��ʳ�Ա
        //cout<<"y = "<<y<<endl;��ȷyΪDerive2��˽�г�Ա
        showxy();
        cout<<"z = "<<z<<endl;
    }
private:
    int z;
};
int main()
{
    Base op1;
    op1.setx(1);
    op1.showx();
    Derive1 op2;
    op2.setxy(2,3);
    op2.showxy();
    Derive2 op3;
    op3.setxyz(4,5,6);
    op3.showxyz();
    return 0;
}