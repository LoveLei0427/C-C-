#include<iostream>
#include<stdlib.h>
using namespace std;
int add(int a, int b)
{
	return a + b;
}

//使用命名空间隔离模板 防止多人使用冲突
namespace space{
	//模板简写 用ptr替代T*
	template<class T>using ptr = T*;

}


//起别名 C语言的形式
typedef int(*P)(int a, int b);
//c++形式
using Func = int(*)(int a, int b);
void main()
{

	P p = add;
	std::cout << p(1, 2) << std::endl;  //3
	Func func = add;
	std::cout << func(2, 4);        //6
	//pint指向int类型的指针
	std::cout << std::endl;
	space::ptr<int>pint(new int(3));
	std::cout << *pint << " " << pint << std::endl;  //3   005E9738

	system("pause");
}