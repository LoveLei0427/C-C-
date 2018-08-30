/*类模板声明形式:
template<typename 类型参数>class 类名{类成员声明};
类模板定义对象时：模板名<实际类型名>对象名[(实参表列)];
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
//定义两种数据类型的类模板
template <class T1,class T2>
class Demo{                  //类模板名为Demo
public:
	T1 demo1;
	T2 demo2;
	Demo(T1 t1, T2 t2) :demo1(t1), demo2(t2){}
	void print(){
		cout << demo1 << " " << demo2 << endl;
	}
};
int main()
{
	Demo <int, double>d(10, 9.9);
	d.print();
	system("pause");
}