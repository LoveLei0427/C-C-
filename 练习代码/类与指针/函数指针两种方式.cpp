//����ָ��������ʽ

#include<iostream>

int max(int, int);     //1������ֵ���ͣ�*����������������
int(*p1)(int, int);

typedef int(*PTR)(int,int);//2������������PTR����ֵ��int�� ������int��
PTR p;					//����PTR���ͱ���p


int main(void)
{	
	
	p1 = max;
	(*p1)(1, 2);
	std::cout << std::endl;


	p = max;
	(*p)(10, 19);
	std::cout << std::endl;
	
	std::cin.get();
}


int max(int i, int j)
{
	int temp;
	temp = (i > j ? i : j);
	std::cout << temp;
	return temp;
}

