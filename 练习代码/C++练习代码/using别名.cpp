#include<iostream>
#include<stdlib.h>
using namespace std;
int add(int a, int b)
{
	return a + b;
}

//ʹ�������ռ����ģ�� ��ֹ����ʹ�ó�ͻ
namespace space{
	//ģ���д ��ptr���T*
	template<class T>using ptr = T*;

}


//����� C���Ե���ʽ
typedef int(*P)(int a, int b);
//c++��ʽ
using Func = int(*)(int a, int b);
void main()
{

	P p = add;
	std::cout << p(1, 2) << std::endl;  //3
	Func func = add;
	std::cout << func(2, 4);        //6
	//pintָ��int���͵�ָ��
	std::cout << std::endl;
	space::ptr<int>pint(new int(3));
	std::cout << *pint << " " << pint << std::endl;  //3   005E9738

	system("pause");
}