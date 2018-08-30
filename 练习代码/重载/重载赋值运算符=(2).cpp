#include<iostream>
#include<cstring>
using namespace  std;
class Equal{
public:
    Equal & operator=(const Equal &ob);
    void print();
    Equal(int i,char *str1);
    Equal();

private:
    int x;
    char *str;
};
void Equal::print()
{
    cout<<x<<" "<<str<<endl;

}
Equal::Equal(){}

Equal::Equal(int i,char *str1)
{
    x = i;
    str = new char[strlen(str1)+1];
    strcpy(str,str1);
}
Equal & Equal::operator=(const Equal &ob)
{
    this->x = ob.x;
    int len = strlen(ob.str);
    str = new char[len+1];
    strcpy(str,ob.str);
    return *this;
}

int main()
{
    Equal ob2(2,"zhangsan");
    Equal ob1(1,"lisi"),ob3;
    ob2.print();
    ob1=ob2;//隐式调用
    ob1.print();
    ob3.operator=(ob2);//显式调用
    ob3.print();
    return 0;
}