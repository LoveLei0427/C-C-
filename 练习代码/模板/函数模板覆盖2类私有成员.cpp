#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
// ����ģ��ʵ��ͨ�ã����Ը��������������ͣ������Ż�
//�ṹ�����û��˽�б���ʱ�ſ���ֱ�Ӹ�ֵ��ʼ��
//���г�Ա���ǹ��е����Ϳ��Ը�ֵ��ʼ�� �������˽�г�Ա���� ������{}��ʼ��

class info{
public:
	char name[20];
	int data;  
	char *p;
	void set(int x)
	{
		this->num = x;
	}
	int get()
	{
		return this->num;//�������� ����Ӱ��ԭname=0
	}
private:
	int  num=0;
	//~info();
};


template<class T>void swap(T &a, T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "ͨ�ú���ģ��" << std::endl;
	std::cout << a << " " << b << std::endl;
}

//���޴˺��� �����н��Ϊͨ�ú���ģ��
template<>
void swap(info &info1, info &info2)
{
	//ͨ��ģ�����ʵ��ͨ�ã�����Լ����������������Ż�
	std::cout << "���к���ģ��" << std::endl;
	info temp = info1;
	info1 = info2;
	info2 = temp;
	//ʵ����ȿ��� Ϊ�ṹ����ָ��*p��ֵ ��ֹһ��ָ��ָ����ڴ��ͷź� ��һָ���ҵ�������ַ

}

int main()
{
	info info1;
	info info2;
	std::strcpy(info1.name, "hello");
	std::strcpy(info2.name, "world");
	info1.data = 100;
	info2.data = 200;
	info1.p = new char[30];
	std::strcpy(info1.p, "��ַ1");
	info2.p = new char[30];
	std::strcpy(info2.p, "��ַ2");
	swap(info1, info2);
	info1.set(11);
	info2.set(22);
	std::cout << info1.name <<" "<<info1.get() <<" "<< info1.data <<" "<<info1.p<< std::endl;
	std::cout << info2.name <<" "<<info2.get() <<" "<< info2.data <<" "<<info2.p<< std::endl;
	std::cin.get();
}