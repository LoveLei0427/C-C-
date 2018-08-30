//成员函数实现单目运算符++
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
    return *this;//this指针是指向当前对象的指针,返回当前对象的值
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