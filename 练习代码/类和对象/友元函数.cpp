#include <iostream>
#include<cstring>
using namespace std;
//ÓÑÔªº¯Êý
class Girl{
    public:
    Girl(char*n,int a)
    {
       name = new char[strlen(n)+1];
       strcpy(name,n);
       age = a;
    }
    ~Girl()
    {
        delete []name;
    }
    friend void disp(Girl &g);

    private:
    char * name;
    int age;
};
void disp(Girl &g)
{
    cout<<"the name of the girl is "<<g.name<<" and the age of her is "<<g.age<<endl;
}
int main()
{
    Girl g1("chenxiaoli",20);
    disp(g1);
    return 0;
}