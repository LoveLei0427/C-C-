#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	int x;
	int y;
	//mutable�������ǲ���constԼ�������Ա,�ڱ�const���εĺ�������Ҳ�ܱ��޸�
	//ֻ�ܹ�����һ����ķǾ�̬���ݳ�Ա
	mutable int z;
	Demo() :x(10), y(20){}
	void printXY()const{
		cout << "x = " << x << endl;
		cout << "y = " << y <<endl;
		z += 1;
	}
	void add(int a){
		x += a;
		y += a;
	}

};
int main(void)
{
	//const���ƶ����ǳ������ɸı�
	const Demo demo1;
	demo1.printXY(); //x=10 y=20
	//demo1.add(1); ����  const���������÷�const��Ա����

	Demo demo2;
	demo2.printXY(); //x=10 y =20 ��const�����������const��Ա����
	//demo2printXY();���� ��const����������const��Ա���� 
	//demo2.add(1);

	system("pause");
}