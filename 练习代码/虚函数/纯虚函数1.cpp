//���д��麯���Ļ����Ϊ������ 
//���麯��ֻ�ڱ������� ���������ʵ����(�������޷�ʵ�������󵫿���ʵ����ָ��)
//�����಻�������ں����Ĳ����Լ�����ֵ���� ������ָ�����
/*Base *test(Base* p)
{Base* pbase(nullptr);return pbase;}*/
//Ӧ�ó����� ��Բ��Բ�ڽ������Ρ����������ε�������ܳ�
#include<iostream>
#include<stdlib.h>
using namespace std;
#define PI 3.14
//����������
class Shape{
public:
	virtual void Area() = 0;
	virtual void Perimeter() = 0;
	Shape(double x){ r = x; }
protected:
	double r;
};
//����Բ������
class Circle :public Shape{
public:
	Circle(double x) :Shape(x){}
	void Area(){
		cout << "Բ�������" <<PI * r * r<< endl;
	}
	void Perimeter(){
		cout << "Բ���ܳ���" << 2 * PI * r << endl;
	}
};
//����Բ�ڽ���������
class In_square :public Shape{
public:
	In_square(double x) :Shape(x){}
	void Area(){
		cout << "�ڽ������ε������" << 2 * r * r << endl;
	}
	void Perimeter(){
		cout << "�ڽ������ε��ܳ���" << 4 * 1.414 * r << endl;
	}
};
//����Բ������������
class Ex_square :public Shape{
public:
	Ex_square(double x) :Shape(x){}
	void Area(){
		cout << "���з��ε������" << 4 * r * r << endl;
	}
	void Perimeter(){
		cout << "���������ε��ܳ���" << 8 * r << endl;
	}
};
int main(void)
{
	Shape* ptr;
	Circle cir(5.0);
	ptr = &cir;
	ptr->Area();
	ptr->Perimeter();

	In_square in_squ(5.0);
	ptr = &in_squ;
	ptr->Area();
	ptr->Perimeter();

	Ex_square ex_squ(5.0);
	ptr = &ex_squ;
	ptr->Area();
	ptr->Perimeter();

	system("pause");
}