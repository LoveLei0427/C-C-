//�麯�������Ǻ���ָ��,��һ�ֶ�̬�����ط�ʽ ����ʱ��̬
//����ԭ��:����Ķ���ָ����ָ�����Ĺ�����������ʱ,ֻ�ܷ����������дӻ���̳еĳ�Ա,���ܷ����������ж���ĳ�Ա

#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(int x){ a = x;}
	void show(){ cout << "Base a=" << a << endl; }
protected:
	int a;
};

class Derived1:public Base{
public:
	Derived1(int x,int y):Base(x){
		b = y;
	}
	void show(){ cout << "Derived1 a=" << a <<" "<<"b="<< b <<endl; }
protected:
	int b;
};

class Derived2 :public Derived1{
public:
	Derived2(int x, int y,int z):Derived1(x,y){ 
		c = z;
	}
	void show(){ cout << "Derived2 a=" << a << " " << "b=" << b << " " << "c=" << c << endl; }
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
	b1->show();  //Base a=2
	b1 = &d2;
	b1->show();  //Base a=4
	
	d1.show();  //Derived1 a=2  b=3
	d2.show();	//Derived2 a=4  b=5 c=6
	((Derived2*)b1)->show(); //Derived2 a=4  b=5 c=6

	system("pause");
}