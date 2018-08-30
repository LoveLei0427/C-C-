#include<iostream>
#include<stdlib.h>
using namespace std;

class Base{
public:
	Base(){
		this->strf = "Fu";
		cout << "Create Fu!" << endl;
	}
	~Base(){
		cout << "Delete Fu!" << endl;
	}
	
	char *strf;
};

class Derived:public Base{
public:
	Derived(){
		this->strd = "Zi";
		cout << "Create Zi!" << endl;
	}

	~Derived(){
		cout << "Delete Zi!" << endl;
	}
	char *strd;
	char ch[1024 * 1024];//�㹻�������� ����������ᱨ��
};
int main()
{
	Base *base1 = new Base;  //Create Fu,Delete Fu
	delete base1;			
	cout << endl;

	Derived *derived1 = new Derived;
	delete derived1;     //Create Fu,Create Zi,Delete Zi,Delete Fu
	cout << endl;

	//ÿ����������ڲ������������ �������ò����ͷŻ�����ڴ�й© �������е�������������Ϊvirtual�麯�� �Ϳ��Խ��
	Base *base2 = new Derived;  //Create Fu,Create Zi,Delete Fu 
	delete base2;
	cout << endl;
	
	//�ڴ�Խ���ͷ�    ��ʱ����
	Derived *derived2 = static_cast<Derived*>(new Base);
	delete derived2;      //Create Fu,Delete Zi,Delete Fu
	
	system("pause");
}