/*用户没有自定义赋值函数的情况下 系统会自动的生成一个默认的运算符函数
X&X::operator(const A&ob){ 成员间赋值... }  但是有指针时会出现“指针悬挂”问题,如下
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
    /*执行此句 调用默认的赋值函数 使两个对象的指针指向同一个空间”book“,
    猪程序结束时,先撤销p2第一次调用析构函数然后delete释放动态分配的空间,撤销p1时因为其指向的空间无法访问出现所谓的指针悬挂问题*/
    return 0;
}
/*程序输出结果为
 * Constructor  Called.
 * Constructor  Called.
 * Destructor Called.---book
 * Destructor Called.---乱码
*/