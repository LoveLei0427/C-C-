#include<iostream>
using namespace  std;
class base{
public:
    base(int a,int b)
    {
        x = a;
        y = b;
    }
    void show()
    {
        cout<<"Base's show:\n";
        cout<<x<<" "<<y<<endl;
    }
private:
    int x;
    int y;
};
class der:public base{
public:
    der(int a,int b,int c):base(a,b)
    {
        z = c;
    }
    void show()
    {
        cout<<"Der's show:\n";
        cout<<"z="<<z<<endl;
    }
private:
    int z;
};
int main()
{
    base mb(10,20),*mp;
    der mc(11,22,33);
    mp = &mb;
    mp->show();
    mp = &mc;
    /*��Ȼָ��ָ��������Ķ��� ���ǵ��õ���Ȼ�ǻ����ͬ����Ա����
      ��Ϊ����Ķ���ָ�����ָ���������Ķ��� ���ǵ���ָ�������������ʱ
      ֻ�ܷ����������дӻ����м̳����ĳ�Ա�����ǹ����������ж���ĳ�Ա*/
    mp->show();
    return 0;
}
/*
������Ϊ:Base's show:
          10 20
          Der's show:
          11 22*/