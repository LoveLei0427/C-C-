/*Ϊ�˽��ǳ�㸴�Ƴ��ֵĴ��� ������ʽ�Ķ��帳ֵ��������غ���
 * ʹ֮������ֵ��ֵ��Ա ���ҶԶ��������Ե��ڴ�ռ� �������ν����㸴��
��=��ֻ������Ϊ��Ա���� ������Ϊ��Ԫ����  friend string &operator(string&s1,string &s2)����ֻ���*/
#include<iostream>
#include<cstring>
using namespace  std;
class STRING{
public:
    STRING(char*s);
    ~STRING();
    STRING &operator=(const STRING &s);
private:
    char *str;
};
STRING::STRING(char *s)
{
    cout<<"Constructor Called."<<endl;
    str = new char[strlen(s) + 1];
    strcpy(str,s);
}
STRING::~STRING()
{
    cout<<"Destructor Called..."<<str<<endl;
    delete str;
}
STRING & STRING::operator=(const STRING &s)
{
    if(this==&s)return *this;//��ֹs=s�����
    delete str;//�ͷŵ�ԭ����
    str = new char[strlen(s.str) + 1];
    strcpy(str,s.str);
    return *this;
}
int main()
{
    STRING s1("book");
    STRING s2("jeep");
    s2 = s1;
    return 0;
}