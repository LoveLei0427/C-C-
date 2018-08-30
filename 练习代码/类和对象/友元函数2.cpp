//一个函数同时定义为两个类的友元函数
//将非成员函数声明为友元函数
#include <iostream>
#include<cstring>
using namespace std;
//对Boy类的提前引用说明
class Boy;
class Girl{
public:
    Girl(char N[],int A);
    //声明函数disp为类Girl的友元函数
    friend void disp(const Girl &,const Boy &);
private:
    char name[25];
    int age;
};
Girl::Girl(char N[], int A)
{
    strcpy(name,N);
    age = A;
}
class Boy{
public:
    Boy(char N[],int A);
    //声明函数disp为类Boy的友元函数
    friend void disp(const Girl &g,const Boy &b);
private:
    char name[25];
    int age;
};
Boy::Boy(char N[], int A)
{
    strcpy(name,N);
    age = A;
}
//定义disp为类Girl和类Boy的友元函数,形参分别是类的对象的引用
void disp(const Girl &g,const Boy &b)
{
    cout<<"the name of the girl is:"<<g.name<<endl;
    cout<<"the age of the girl is:"<<g.age<<endl;
    cout<<"the name of the boy is:"<<b.name<<endl;
    cout<<"the name of the boy is:"<<b.age<<endl;
}
int main()
{
    Girl g1("xiaoli",20);
    Girl g2("xiaowei",18);
    Girl g3("xiaofang",19);
    Boy b1("xiaozhang",22);
    Boy b2("xiaozhao",23);
    Boy b3("xiaowang",25);
    disp(g1,b1);
    disp(g2,b2);
    disp(g3,b3);
    return 0;
}