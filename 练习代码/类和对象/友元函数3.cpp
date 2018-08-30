//将成员函数声明为友元函数
#include <iostream>
#include<cstring>
using namespace std;
class Girl;
class Boy{
public:
    Boy(char N[],int A)
    {
        strcpy(name,N);
        age = A;
    }
    void disp(Girl &);
    ~Boy()
    {
        delete []name;
    }
private:
    char name[25];
    int age;
};
class Girl{
public:
   Girl(char N[],int A)
    {
        strcpy(name,N);
        age = A;
    }
    friend void Boy::disp(Girl &);
    ~Girl()
    {
        delete []name;
    }
private:
    char name[25];
    int age;
};
void Boy::disp(Girl &g)
{
        cout<<"the name of the boy is :"<<name<<endl;
        cout<<"the name of the boy is :"<<age<<endl;
        cout<<"the name of the girl is:"<<g.name<<endl;
        cout<<"the age of the girl is :"<<g.age<<endl;
}
int main()
{
    Boy b1("Jack",25);
    Girl g1("Rose",23);
    b1.disp(g1);
    return 0;
}