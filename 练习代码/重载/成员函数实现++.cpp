//��Ա����ʵ�ֵ�Ŀ�����++
#include<iostream>
using namespace std;
class Coord{
public:
    Coord(int i,int j);
    void print();
    Coord operator++();
private:
    int x;
    int y;
};

Coord::Coord(int i, int j):x(i),y(j){}
Coord Coord::operator++ ()
{
    ++x;
    ++y;
    return *this;//thisָ����ָ��ǰ�����ָ��,���ص�ǰ�����ֵ
}
void Coord::print()
{
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
}

int main()
{
    Coord obj(10,20);
    obj.print();
    obj.operator++();
    obj.print();
    ++obj;
    obj.print();
    return 0;
}