/*�û�û���Զ��帳ֵ����������� ϵͳ���Զ�������һ��Ĭ�ϵ����������
X&X::operator(const A&ob){ ��Ա�丳ֵ... }  ������ָ��ʱ����֡�ָ�����ҡ�����,����
*/

#include<iostream>
#include<cstring>
using namespace  std;
class STRING{
public:
    STRING(char*s)
    {
        cout<<"Constructor Called."<<endl;
        str = new char[strlen(s) + 1];
        strcpy(str,s);
    }
    ~STRING()
    {
        cout<<"Destructor Called---"<<str<<endl;
        delete str;
    }
private:
    char *str;
};
int main()
{
    STRING p1("book");
    STRING p2("jeep");
    p2 = p1;
    /*ִ�д˾� ����Ĭ�ϵĸ�ֵ���� ʹ���������ָ��ָ��ͬһ���ռ䡱book��,
    ��������ʱ,�ȳ���p2��һ�ε�����������Ȼ��delete�ͷŶ�̬����Ŀռ�,����p1ʱ��Ϊ��ָ��Ŀռ��޷����ʳ�����ν��ָ����������*/
    return 0;
}
/*����������Ϊ
 * Constructor  Called.
 * Constructor  Called.
 * Destructor Called.---book
 * Destructor Called.---����
*/