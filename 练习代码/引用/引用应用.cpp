#include<iostream>
using namespace std;
int &max(int &num1,int &num2);
int &min(int &num1,int &num2);
main()
{
	int num1,num2;
	cout<<"请输入第一个数:"<<endl;
	cin>>num1;
	cout<<"请输入第二个数:"<<endl;
	cin>>num2;
	max(num1,num2)=0;
	cout<<"\n找出最大数并赋值为0后，两数分别为:"<<endl;
	cout<<num1<<' '<<"and"<<' '<<num2<<endl;
	cout<<"现在再输入两个数:"<<endl;
	cout<<"请输入第一个数:"<<endl;
	cin>>num1;
	cout<<"请输入第二个数:"<<endl;
	cin>>num2;
	min(num1,num2)=0;
	cout<<"\n找出最小数并赋值为0后，两个数分别为:"<<endl;
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