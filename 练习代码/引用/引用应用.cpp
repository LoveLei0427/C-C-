#include<iostream>
using namespace std;
int &max(int &num1,int &num2);
int &min(int &num1,int &num2);
main()
{
	int num1,num2;
	cout<<"�������һ����:"<<endl;
	cin>>num1;
	cout<<"������ڶ�����:"<<endl;
	cin>>num2;
	max(num1,num2)=0;
	cout<<"\n�ҳ����������ֵΪ0�������ֱ�Ϊ:"<<endl;
	cout<<num1<<' '<<"and"<<' '<<num2<<endl;
	cout<<"����������������:"<<endl;
	cout<<"�������һ����:"<<endl;
	cin>>num1;
	cout<<"������ڶ�����:"<<endl;
	cin>>num2;
	min(num1,num2)=0;
	cout<<"\n�ҳ���С������ֵΪ0���������ֱ�Ϊ:"<<endl;
	cout<<num1<<' '<<"and"<<' '<<num2<<endl;
	return 0;
}
int &max(int &num1,int &num2)
{
	return(num1>num2)?num1:num2;
}
int &min(int &num1,int &num2)
{
	return(num1<num2)?num1:num2;
}