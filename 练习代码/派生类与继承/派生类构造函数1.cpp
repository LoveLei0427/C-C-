/*������Ĺ��캯��
�����к��д������Ĺ��캯��ʱ,��������붨�幹�캯��
*/
#include<iostream>
using namespace std;
class Student{
public:
    Student(string num1,string name1,float score1);
    void show()
    {
        cout<<"Number :"<<num<<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"Score :"<<score<<endl;
    }
protected:
    string num;
    string name;
    float score;
};
Student::Student(string num1,string name1,float score1)
{
    num = num1;
    name = name1;
    score = score1;
}
class UStudent:public Student{
public:
    //���������๹�캯��Ҫ׺�ϻ��๹�캯���������
    UStudent(string num1,string name1,float score1,string major1)
        :Student(num1,name1,score1)
    {
        major = major1;
    }
    void show1()
    {
        show();
        cout<<"Major :"<<major<<endl;
    }
private:
    string major;
};
int main()
{
    UStudent stu("0001","zhangsan",95,"Computer");
    stu.show1();
    return 0;
}