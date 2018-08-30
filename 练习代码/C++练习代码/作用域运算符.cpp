#include<iostream>
using namespace std;
int aver;
int main(void)
{
	::aver = 100;		//全局变量赋值
	int aver;
	aver = 99;			//局部变量赋值
	cout << "global aver = "<<::aver << endl;
	cout << "local aver = " << aver << endl;
	system("pause");
}