#include<iostream>
using namespace std;
int main()
{
	int i;
	int &j=i;
	i=30;
	cout<<"i="<<i<<' '<<"j="<<j<<"\n";
	j=80;
	cout<<"i="<<i<<' '<<"j="<<j<<"\n";
	cout<<"����i�ĵ�ַ:"<<&i<<endl;
	cout<<"����j�ĵ�ַ:"<<&j<<endl;
	return 0;
}