/*��ģ��������ʽ:
template<typename ���Ͳ���>class ����{���Ա����};
��ģ�嶨�����ʱ��ģ����<ʵ��������>������[(ʵ�α���)];
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
//���������������͵���ģ��
template <class T1,class T2>
class Demo{                  //��ģ����ΪDemo
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