#include<iostream>
using namespace std;
void swap(int &m,int &n)
{
	int temp;
	temp=m;
	m=n;
	n=temp;
}
int main()
{
	int a=5,b=10;
	cout<<"a="<<a<<" b="<<b<<endl;	//	ʵ��a,b�����ͱ�������ͨ���������޸���ֵ
	swap(a,b);
	cout<<"a="<<a<<" b="<<b<<endl;
	return 0;
}
