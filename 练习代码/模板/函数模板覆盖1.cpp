#include<iostream>

// ����ģ��ʵ��ͨ�ã����Ը��������������ͣ������Ż�
//�ṹ�����û��˽�б���ʱ�ſ���ֱ�Ӹ�ֵ��ʼ��
//���г�Ա���ǹ��е����Ϳ��Ը�ֵ��ʼ��

class info{
public:
	char name[20];
	double db;
	int data;
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
}

int main()
{
	info info1 = { "hello", 20.9, 10 };
	info info2 = { "world", 20.8, 1 };
	swap(info1, info2);
	std::cout << info1.name <<  info1.db <<  info1.data << std::endl;
	std::cout << info2.name <<  info2.db <<  info2.data << std::endl;
	std::cin.get();
}
