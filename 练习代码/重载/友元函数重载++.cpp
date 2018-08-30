/*��Ԫ���������ֵ��÷����ǵȼ۵� 
1.��˫Ŀ��������� aa@bb�ȼ���operator(aa,bb)
2.�Ե�Ŀ��������� @aa�ȼ���operator@(aa)
*/
#include<iostream>
using namespace std;
class Complex{
public:
    void print();
    Complex (int i = 0,int j = 0);
    friend Complex operator++(Complex &obj);
private:
    int x;
    int y;
};
Complex::Complex (int i,int j)
{
    x = i;
    y = j;
}
Complex operator++(Complex &obj)
{
    ++obj.x;
    ++obj.y;
    return obj;
}
void Complex::print()
{
    cout<<"x :"<<x<<endl;
    cout<<"y :"<<y<<endl;
}
int main()
{
    Complex ob(10,20);
    ob.print();
    operator++(ob);//��ʽ����
    ob.print();
    ++ob;//��ʽ����
    ob.print();
    return 0;
}