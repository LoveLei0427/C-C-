/*
1�����������麯�������¶���ʱ,����ԭ�����������ȫ��ͬ
2���麯���ǳ�Ա���� ��������Ԫ������̬��Ա����
3��ʹ�ö�����.�����麯���Ǿ�̬���෽ʽû���õ��麯������ ֻ��ͨ������ָ������麯�����ܻ������ʱ��̬
4���麯��ռ���ĸ��ֽ� �����Ǻ���ָ��
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(int x){ a = x;}
	//��ֻ���������� �����ⶨ��ʱ�����ټ�virtual
	virtual void show(){ cout << "Base a=" << a << endl; }
protected:
	int a;
};

class Derived1:public Base{
public:
	Derived1(int x,int y):Base(x){
		b = y;
	}
	virtual void show(){ cout << "Derived1 b=" << b <<endl; }
protected:
	int b;
};

class Derived2 :public Derived1{
public:
	Derived2(int x, int y,int z):Derived1(x,y){ 
		c = z;
	}
	virtual void show(){ cout << "Derived2 c=" << c <<endl; }
protected:
	int c;
};
int main(void)
{
	Base b(1);
	Derived1 d1(2, 3);
	Derived2 d2(4,5,6 );
	Base* b1;
	b1 = &b;
	b1->show(); //Base a=1
	b1 = &d1;
	b1->show();  //Derived1 b=3
	b1 = &d2;
	b1->show();  //Derived2 c=6
	
	d1.show();   //Derived1 b=3 
	d2.show();	//Derived2 c=6
	((Derived2*)b1)->show(); //Derived2 c=6

	system("pause");
}