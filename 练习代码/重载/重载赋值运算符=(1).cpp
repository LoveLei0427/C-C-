//����֮�����ֱ����=��ֵ���ǵ�һ�����а���ָ�����͵ĳ�Ա����ʱ,���ܻ��������.���Ҫ����
#include<iostream>
using namespace  std;
class Equal{
public:
    Equal & operator=(const Equal &ob);
    /*���ظ�ֵ����
     * Ҳ����д��void operator(Equal&a)
     * ���ǲ������κ�ֵͬʱ��֧����ʽ��ֵ����a=b=c*/
    void print();
    Equal(int i=0);
private:
    int x;
};
Equal::Equal(int i)
{
    x = i;
}

void Equal::print()
{
    cout<<x<<endl;
}

Equal & Equal::operator=(const Equal &ob)
{
    if(this!=&ob)//�����ж�����ν
    {
        this->x = ob.x;
    }
    return *this;
}

int main()
{
    Equal ob2(2);
    Equal ob1,ob3;
    ob2.print();
    ob1=ob2;//��ʽ����
    ob1.print();
    ob3.operator=(ob2);//��ʽ����
    ob3.print();
    return 0;
}