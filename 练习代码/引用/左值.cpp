#include<iostream>
#include<stdlib.h>
using namespace std;

//ջ�Ϻ���
int & get()
{
	int  a = 1; //a�����ջ�� ��������ʱ�����ڴ�����ʱ����
	int ra(a);
	cout << &a << endl;
	return a;
}


//���Ϻ���--ָ��
int * & getdata()
{
	int *p;//P��ջ��ָ������ڴ�
	cout << &p;
	p = new int;
	*p = 10;
	int * &rp = p;//����ָ�� ����ִ����Ϻ�ָ���ͷŵ���ռ�� ���ڴ����
	cout << rp << endl;
	return rp;//�������õ�ָ��
}




int main(void)
{
	int num1(5);
	int num2(10);
	int *pnum(&num1);

	//��ֵ����ʵ����ָ��ʵ��
	int * &rpnum = pnum;//����ָ����������� int*������������
	cout<< *pnum <<" "<< *rpnum<< " "<<num2<< " "<< num2<<endl;//5 5 10 5
	
	pnum = &num2;
	cout<< *pnum << " "<< *rpnum<<" "<<num2<<" "<<num2<< endl;//10 10 10 5
	cout<< &pnum <<" "<< &rpnum << " " << &num1 << " " << &num2 << endl;
	cout << "***************" << endl;
	
	int &ra = get();	
	cout << ra << endl;//1	
	cout << "111111" << endl;
	cout << ra << endl;//
	
	cout << "***************" << endl;
	 
	int * &rp = getdata();
	int *prp = rp;
	cout << *rp << endl;//10
	cout << *prp<<endl;//10 ��Ϊp��ջ�������ͷſ�������һ��ָ�뱣����ϵ�ַ������delete prp

	cout << *rp << endl;//��ʱrp���ͷ� ���

	cout << "***************" << endl;
	int *p;
	p = &num1;//&num1����ڼĴ�����
	int * &&rnum = &num1;//&&Ϊ������ֵ,���ڶ��󿽱�
	p = rnum;
	cout << *p <<*rnum<< endl;//5 5
	system("pause");
}