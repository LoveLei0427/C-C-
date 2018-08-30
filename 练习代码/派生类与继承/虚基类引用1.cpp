#include<iostream>
#include<cstring>
using namespace std;
class Data_rec{
public:
    Data_rec(string name1,string sex1,int age1)
    {
        name = name1;
        sex = sex1;
        age = age1;
    }
protected:
    string name;
    string sex;
    int age;
};

class Student:virtual public Data_rec{
public:
    Student(string name1,string sex1,int age1,string major1,double score1):
        Data_rec(name1,sex1,age1)
    {
        major = major1;
        score = score1;
    }
protected:
    string major;
    double score;
};

class Employee:virtual public Data_rec{
public:
    Employee(string name1,string sex1,int age1,string dept1,double salary1):
    Data_rec(name1,sex1,age1)
    {
        dept = dept1;
        salary = salary1;
    }
protected:
    string dept;
    double salary;
};

class E_Student:public Employee,public Student{
public:
    E_Student(string name1,string sex1,int age1,string major1,double score1,string dept1,double salary1):
        Data_rec(name1,sex1,age1),Student(name1,sex1,age1,major1,score1),Employee(name1,sex1,age1,dept1,salary1)
    {}
    void print();
};
void E_Student::print()
{
    cout<<"Name :"<<name<<endl;
    cout<<"Sex  :"<<sex<<endl;
    cout<<"Age  :"<<age<<endl;
    cout<<"Score:"<<score<<endl;
    cout<<"Major:"<<major<<endl;
    cout<<"Dept :"<<dept<<endl;
    cout<<"Salary:"<<salary<<endl;
}

int main()
{
    E_Student my("zhangsan","female",25,"Computer",99,"Office",16000);
    my.print();
    return 0;
}