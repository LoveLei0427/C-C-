/*����Ϊ�麯����virtual����ָʾ������,����ָ��ָʾ��ʵ�ʶ���,���øö���ĳ�Ա����(��̬����)
�麯���Ķ���  virtual �������� ��������(������){} ���ڻ�����ֻ�����麯��ԭ�� �����ⶨ��ʱ�����ټ�virtual
�麯�������ǳ�Ա���� ��������Ԫ���� �����Ǿ�̬��Ա����
�����еĳ�Ա����������Ϊ�麯��������ڶ�������������¶���
 �������� ������ �������� ����������Ҫ��ԭ������ͬ
*/
#include<iostream>
using namespace  std;
class Base{
public:
    Base(int a,int b)
    {
        x = a;
        y = b;
    }
    virtual void show()    {
        cout<<"Base's Show:\n";
        cout<<x<<" "<<y<<endl;
    }
private:
    int x,y;
};
class Derived:public Base{
public:
    Derived(int a,int b,int c):Base(a,b)
    {
        z = c;
    }
    virtual void show()//�����������¶����麯��
    {
        cout<<"Derived's Show:\n";
        cout<<z<<endl;
    }
private:
    int z;
};
int main()
{
    Base ma(10,20),*op;
    Derived mb(11,22,33);
    op = &ma;
    op->show();
    op = &mb;
    op->show();
    return 0;
}
/*���н��:Base's Show:
          10 20
          Derived's Show:
          33*/