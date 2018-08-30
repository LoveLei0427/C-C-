//函数模板声明形式: template<typename T>返回类型  函数名(模板形参表){函数体}
//函数的形参可以是类模板或其引用 对应实参是该类模板实例化的模板类对象
//一个函数拥有类模板参数时 函数定是函数模板
#include<iostream>
#include<stdlib.h>
using namespace std;
//1
template<typename T>  //模板声明
T max(T x, T y){     //函数模板定义 参数为模板形参表
	return (x > y) ? x : y;
}
//2
template<typename T>
T sum(T* array, int size = 0){
	T total = 0;
	for (int i = 0; i < size; i++){
		total += array[i];
	}
	return total;
}

int main()
{
	int i1 = 1, i2 = 2;
	char c1 = 'k', c2 = 'j';
	//调用函数模板，i1和i2为模板实参
	cout << "较大的整数是:" << max(i1, i2) << endl;
	cout << "较大的字符是:" << max(c1, c2) << endl;
	cout << "----------------"<< endl;
	int intarray[] = {1,2,3,4,5,6,7,8,9,10};
	double doublearray[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0};
	int intsum = sum(intarray, 10);
	int doublesum = sum(doublearray, 10);
	cout <<"这十个整数的和是:" << intsum << endl;
	cout << "这十个双精度数的和是:" << doublesum << endl;

	system("pause");
	return 0;
}