/*
auto_ptr��ģ����  ���ڶ�̬�ڴ����
����������ָ��Ķ��� ���Խ�newֱ�ӻ��ӻ�õĵ�ַ�������ֶ��� 
���������ʱ �����������Զ�ʹ��delete�ͷ�
ע�⣺1����ͷ�ļ�<memory>2auto_ptr��������������ʽ��3��newһ��ʹ�ö�����new[]
*/
#include<iostream>
#include<stdlib.h>
#include<memory>
#include<string>
using namespace std;

void SmartPointer(string &str)
{
	auto_ptr<string>pd(new string(str));
	/*
	auto_ptr<string>pd;
	string *str=new string;
	pd = str;
	����auto_ptr<string>pd=str;
	���� ������ָ�뵽auto_ptr�������ʽ����ת��
	*/
	cout << *pd<< endl;
}
void main()
{
	string s("C++!");
	SmartPointer(s);
	system("pause");
}