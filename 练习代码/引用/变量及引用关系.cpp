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
	cout<<"变量i的地址:"<<&i<<endl;
	cout<<"变量j的地址:"<<&j<<endl;
	return 0;
}