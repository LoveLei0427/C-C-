//友元函数重载单目运算符-
#include <iostream>
using namespace std;
class Coord{
public:
    void print();
    friend Coord operator-(Coord &a);
    Coord(int x1 = 0);
private:
    int x;
};
Coord::Coord(int x1)
{
    x = x1;
}
Coord operator-(Coord &a)
{
    a.x = -a.x;
    return a;
}
void Coord::print()
{
    cout<<"x = "<<x<<endl;
}
int main()
{
    Coord ob1(100),ob2,ob3;
    ob1.print();
    ob2 = operator-(ob1);
    ob2.print();
    ob3 = -ob1;
    ob3.print();
    ob2.print();
    ob1.print();
    return 0;
}