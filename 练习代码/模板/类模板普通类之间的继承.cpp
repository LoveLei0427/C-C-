#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//ģ����֮��ļ̳�  ���ͱ��봫��
template<typename T>
class Demo{
public:
	T x;
	Demo(T t) :x(t){}
	void print(){ cout << x << endl; }
};

template<typename T>
class newDemo :public Demo<T>{   //�̳е�ʱ�������ȷ����
public:
	T y;
	newDemo(T t1, T t2) :Demo(t1), y(t2){}
	void print(){ cout << x << " " << y << endl; }
};

//2 ��ģ��̳���ͨ�� �������
class XYZ{
public:
	XYZ(int a, int b, int c){ 
	x = a;
	y = b;
	z = c;
	}
	void print(){ cout << x << " " << y << " " << z << endl; }
protected:
	int x, y, z;
};

template<typename T>
class newXYZ :public XYZ{
public:
	newXYZ(T t1, int a, int b, int c) :XYZ(a,b,c),a(t1){}
	void print(){
		cout << "Ta=" << a << endl;
		cout << x << " " << y << " " << z << endl;
	}
protected:
	T a;
};

//3����ͨ��̳���ģ�� ��ȷ���Ͳ�ʵ������ģ��
class Derived_newXYZ:public newXYZ<int>  //��ģ�����ʵ����
{
public:
	int demo = 1000;
	Derived_newXYZ(int a, int b, int c, int d) :newXYZ<int>(a, b, c, d){}
	
	void print(){ cout << demo <<" "<< x << " " << y << " " << z << " " << a <<endl; }
}


int main(void)
{
	//1     9.8   8.9
	newDemo<double>test( 9.8,8.9);
	test.print();
	Demo<int>*p = new newDemo<int>(10, 9);
	p->print();//10 ����Demo��print����Ϊ�麯�����ӡ10 9
	
	//2    Ta=China 10 20 30
	string str = "China";
	newXYZ<std::string>test2(str,10,20,30);
	test2.print();    

	//3   
	Derived_newXYZ d_newxyz(1, 2, 3, 4);
	d_newxyz.print();
	system("pause");
}