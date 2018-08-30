/*类模板外定义成员函数形式：
template<typename 类型参数>
函数类型  类名<类型参数>::成员函数名(形参表)
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>    //模板声明
class Compare{        //函数模板定义 参数为模板形参表
public:
	Compare(T a,T b);
	T max();
private:
	T x, y;
};

template<typename T>
Compare<T>::Compare(T a, T b){
	x = a;
	y = b;
}
template<typename T>
T Compare<T>::max(){
	return (x > y) ? x : y;
}

int main()
{
	Compare<int>c1(1, 2);
	cout << "较大的值是:" <<c1.max()<< endl;
	system("pause");
	return 0;
}