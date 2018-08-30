//一个类中嵌套另一个类的对象作为数据成员成为类的组合
//该内嵌对象称为对象成员,也称为子对象
#include <iostream>
#include<cstring>
using namespace std;
class Score{
public:
    Score(float c,float e,float m);
    void show();
private:
    float computer;
    float english;
    float math;
};
Score::Score(float c, float e, float m)
{
    computer = c;
    english = e;
    math = m;
}
void Score::show()
{
    cout<<"The score of computer is:"<<computer<<endl;
    cout<<"The score of english is:"<<english<<endl;
    cout<<"The score of math is:"<<math<<endl;
}
class Student{
public:
    Student(char *name1,char *num1,float s1,float s2,float s3);
    ~Student();
    void show();
private:
    char *name;
    char *num;
    Score score1;
};
Student::Student(char *name1,char *num1,float s1,float s2,float s3):score1(s1,s2,s3)
{
    name = new char[strlen(name1)+1];
    strcpy(name,name1);
    num = new char[strlen(num1)+1];
    strcpy(num,num1);
}
Student::~Student()
{
    delete []name;
    delete []num;
}
void Student::show()
{
    cout<<"Name:   "<<name<<endl;
    cout<<"Number: "<<num<<endl;
    score1.show();
}
int main()
{
    Student stu1("Jack","900911",90,99,88);
    Student stu2("Rose","900912",80,89,100);
    stu1.show();
    cout<<"***********************"<<endl;
    stu2.show();
    return 0;
}
