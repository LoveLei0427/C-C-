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
	cout<<"a="<<a<<" b="<<b<<endl;	//	实参a,b是整型变量，可通过引用来修改其值
	swap(a,b);
	cout<<"a="<<a<<" b="<<b<<endl;
	return 0;
}
