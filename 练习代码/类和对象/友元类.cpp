/*��������Boy����Girl����Ԫ��,��֮��һ������
Ҫ������Gril���Ƿ�����Ӧ������
*/
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
    void disp1(Girl &);
    void disp2(Girl &);
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
   //��Boy����Girl����Ԫ��,����Boy�е����г�Ա����ΪGirl�����Ԫ����
    friend Boy;
    ~Girl()
    {
        delete []name;
    }
private:
    char name[25];
    int age;
};
void Boy::disp1(Girl &g)
{
        cout<<"the name of the boy is :"<<name<<endl;
        cout<<"the name of the girl is:"<<g.name<<endl;
}
void Boy::disp2(Girl &g)
{
        cout<<"the age of the boy is :"<<age<<endl;
        cout<<"the age of the girl is:"<<g.age<<endl;
}
int main()
{
    Boy b1("Jack",25);
    Girl g1("Rose",23);
    b1.disp1(g1);
    b1.disp2(g1);
    return 0;
}