/*
����ָ�����ø������ ��ȫ��������
����ָ�������������ͻḲ�Ǹ����ͬ������
����ָ�������������ֻ�����ø����еĺ���
����ָ�����ø���������಻�漰�ڲ����ݵĺ�������óɹ���֮ʧ�� ����ָ�����ʹ��
�������->�������������������ĸ�ʽ�������ø��ຯ��

������˽�еģ������ǹ����
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(){
		this->strf = "Base";
	}
	~Base(){}
	void print(){
		cout << this->strf << endl;
	}
	void Demof(){
		cout << "I am Base" << endl;
	}
	char *strf;
};

class Derived:public Base{
public:
	Derived(){
		this->strd = "Derived";
	}

	~Derived(){}

	void print(){
		cout << this->strd << endl;
	}

	void Demod(){
		cout << "I am Derived" << endl;
	}
	char *strd;
};
int main(void)
{
	//�������ָ���෽��
	Base base1;
	base1.print();  //Base
	base1.Demof();	//I am Base
	Base *base2 = new Base;
	base2->print(); //Base
	base2->Demof(); //I am Base

	cout << "---------------------" << endl;
	//�������ָ�����෽��
	//���า�Ǹ���ͬ���ķ���
	Derived derived1;
	derived1.Derived::print();   //Derived
	derived1.Demod();	//I am Derived
	Derived *derived2 = new Derived;
	derived2->print(); //Derived
	derived2->Demod(); //I am Derived

	cout << "---------------------" << endl;
	//�������ָ�����෽��
	Base *pb = new Derived;
	pb->print();	//Base
	pb->Demof();    //I am Base

	cout << "---------------------" << endl;
	//�������ָ���෽��
	//ֱ��ת������Derived *pb = new Base;
	Base* pb2 = new Base;
	//static_cast��Ҫ�õ��麯������֮��ת��
	Derived* pd = static_cast<Derived*>(pb2); //����͸������֮��ת���õ�
	pd->Base::print();  //����дΪpd->print(); �ڸ����д˴��ڴ�Ϊ�ջᱨ��	
	pd->Derived::Demof();   //I am Base  �ȼ���pd->Demof();
	pd->Demod();     //I am Base
	//cout<<pd->strd << endl;  //���� ֱ�ӵ��� �������ڲ������ĺ���
	system("pause");
}