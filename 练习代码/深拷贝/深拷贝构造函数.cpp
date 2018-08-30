
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Test{
public:
	//Test() = delete;����Ĭ�����ɵĹ��캯������ʹ���޷�ʵ����
	//Test()�ȼ���Test()=default;
	Test(){
		cout << "Create Test();" << endl;
	}
	//Test(const Test& t)=delete;�������캯�� ��ֹ�ⲿʹ��ֵ
	Test(int x, int y){
		a = x;
		b = y;
	}
	~Test(){
		cout << "~Test();" << endl;
	}
	void print(){
		cout << a << "	" << b << endl;
	}

private:
	int a;
	int b;
};

//���������ǳ����
class MyTest{
public:
	char *p;
	int length;
	MyTest(int n, char *str){
		length = n;
		p = new char[length];
		memset(p, 0, length);
		strcpy(p,str);
	}

	MyTest(const MyTest& mytest){
		/*
		�ֶ�ʵ��ǳ����	
		this->p = mytest.p;
		this->length = mytest.length;
		*/
		//���
		this->p = new char[mytest.length];
		this->length = mytest.length;
		memset(p, 0, this->length);
		strcpy(this->p, mytest.p);
	}

	~MyTest(){
		delete[]p;
	}

private:

};

int main(void)
{
	Test test1(10, 100);
	Test test2(test1);
	//Test test3(100);
	test1.print();   //10  100
	test2.print();	//10  100

	MyTest str1(10, "hello");
	cout << str1.p << endl;  //hello
	MyTest str2(str1); //hello
	cout << str2.p << endl;

	//ǳ����ֻ�Ǹ���ֵ ��ָ����Ӱ��
	MyTest *point1 = new MyTest(10, "world!");
	cout << point1->p << endl;   //world!
	MyTest *point2 = new MyTest(*point1);
	//delete point1;��ʱ�����ڴ� �ᱨ�� point2�Ҳ���λ��  ��Ҫ���
	cout << point2->p << endl;	//world!

	//���
	MyTest *point3 = new MyTest(10, "world!");
	cout << point3->p << endl;   //world!
	MyTest *point4 = new MyTest(*point1);
	delete point3;
	//����
	cout << point4->p << endl;	//world!

	system("pause");
}

//class ClassTest{
//
//public:
//	ClassTest(){
//		cout << "Class Creat!" << endl;
//	}
//
//	void print()
//	{
//		cout << "HelloWorld!" << endl;
//	}
//	~ClassTest(){
//
//		cout << "Class Delete!" << endl;
//	}
//
//private:
//
//};
//void Run()
//{
//	ClassTest test;
//}
