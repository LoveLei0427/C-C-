//���ж�������Ա�������๹�캯����ִ��˳��

/*���캯��ִ��˳��
1.���๹�캯�������̳�ʱ��˳������������е�˳��
2.�Ӷ����캯����������������˳��
3.�������Լ��Ĺ��캯��
��������ִ��ѭ���빹�캯���෴
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
        Student::print();//�����������¶����Ա����print�����û����Ա������һ���ʽΪ����::��������
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
    /*auditor1����������auditor2���Ե���˳��һ��
     * �������ȵ���auditor2
    */
    Student auditor1;
    Student auditor2;
};
int main()
{
    UStudennt stu("100100","zhangsan",90,"200200","lisi",99,"300300","wangwu",88,"Computer");
    stu.print();//���õ��������ຯ��
    stu.print_auditor1();
    stu.print_auditor2();
    return 0;
}