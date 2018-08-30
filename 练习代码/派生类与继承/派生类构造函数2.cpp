//含有多个对象成员的派生类构造函数的执行顺序

/*构造函数执行顺序
1.基类构造函数（按继承时的顺序而不是声明中的顺序）
2.子对象构造函数（按类中声明的顺序）
3.派生类自己的构造函数
析构函数执行循序与构造函数相反
 */
#include<iostream>
using namespace std;
class Student{
public:
    Student(string num1,string name1,float score1);
    void print();
protected:
    string num;
    string name;
    float score;
};
Student::Student(string num1, string name1, float score1)
{
    num = num1;
    name = name1;
    score = score1;
}
void Student::print()
{
    cout<<"Number: "<<num<<endl;
    cout<<"Nname : "<<name<<endl;
    cout<<"Score : "<<score<<endl;
}
class UStudennt:public Student{
public:
    UStudennt(string num1,string name1,float score1,
              string num2, string name2, float score2,
              string num3, string name3, float score3,string major1)
        :Student(num1,name1,score1)
        ,auditor2(num3,name3,score3)
        ,auditor1(num2,name2,score2)
        {
            major = major1;
        }

    void print()
    {
        cout<<"Formal Student:"<<endl;
        Student::print();//派生类中重新定义成员函数print，调用基类成员函数（一般格式为类名::函数名）
    }
    void print_auditor1()
    {
        cout<<"Auditor :"<<endl;
        auditor1.print();

    }
    void print_auditor2()
    {
        cout<<"Auditor :"<<endl;
        auditor2.print();
    }
private:
    string major;
    /*auditor1的声明先于auditor2所以调用顺序一致
     * 而不是先调用auditor2
    */
    Student auditor1;
    Student auditor2;
};
int main()
{
    UStudennt stu("100100","zhangsan",90,"200200","lisi",99,"300300","wangwu",88,"Computer");
    stu.print();//调用的是派生类函数
    stu.print_auditor1();
    stu.print_auditor2();
    return 0;
}