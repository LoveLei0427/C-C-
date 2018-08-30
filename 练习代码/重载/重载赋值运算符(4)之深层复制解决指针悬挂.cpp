/*为了解决浅层复制出现的错误 必须显式的定义赋值运算符重载函数
 * 使之不但赋值数值成员 并且对对象分配各自的内存空间 这就是所谓的深层复制
“=”只能重载为成员函数 若重载为友元函数  friend string &operator(string&s1,string &s2)会出现混乱*/
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
    if(this==&s)return *this;//防止s=s的情况
    delete str;//释放掉原区域
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