#include<iostream>
using namespace std;
int mul(int x,int y)
{
	return x*y;
}
int mul(int x,int y,int z)
{
	return x*y*z;
}
int main()
{
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	cout<<a<<'*'<<b<<'='<<mul(a,b)<<endl;
	cout<<a<<'*'<<b<<'*'<<c<<'='<<mul(a,b,c)<<endl;
	return 0;
}