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
        cout<<x<<endl;
    }
private:
    int x;
};
//��������Base��˽��������Derived
class Derived:private Base
{
public:
    void setxy(int n,int m)
    {
        setx(n);
        //����ĺ�������������Ϊ˽�г�Ա,������ĳ�Ա�������Է���
        y = m;
    }
    void showxy()
    {
        //cout<<x<<endl;����,�������Ա��������ֱ�ӷ��ʻ����˽�г�Ա
        showx();
        cout<<y<<endl;
    }
private:
    int y;
};
int main()
{
    Derived obj;
    /*��������������������Ϊ˽�г�Ա,����������ܷ���
    obj.setx(9);
    obj.showx();
     */
    obj.setxy(10,20);
    obj.showxy();
    return 0;
}
