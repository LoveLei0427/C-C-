#include<iostream>
using namespace std;
int aver;
int main(void)
{
	::aver = 100;		//ȫ�ֱ�����ֵ
	int aver;
	aver = 99;			//�ֲ�������ֵ
	cout << "global aver = "<<::aver << endl;
	cout << "local aver = " << aver << endl;
	system("pause");
}