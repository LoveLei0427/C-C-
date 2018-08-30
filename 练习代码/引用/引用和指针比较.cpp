#include<iostream>
using namespace std;
int main()
{
	int i=15;
	int *iptr=&i;
	int &rptr=i;
	cout<<"i="<<i<<endl;
	cout<<"*iptr="<<*iptr<<endl;
	cout<<"rptr="<<rptr<<endl;
	i=29;
	cout<<"after changing i to 29:"<<endl;
	cout<<"i="<<i<<endl;
	cout<<"*iptr="<<*iptr<<endl;
	cout<<"rptr="<<rptr<<endl;
	return 0;
}