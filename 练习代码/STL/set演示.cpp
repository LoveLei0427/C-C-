#include<iostream>
#include<set>
#include<stdlib.h>
using namespace std;

int main()
{

	multiset<int>myset; //����һ�����������ļ���
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(20);
	myset.insert(60);

	//Ѱ�ҵ�һ�����ϵ�
	auto find1 = myset.find(30);
	cout << *find1 << endl;

	//�ҵ������������ ��������Ԫ��
	auto finddata = myset.equal_range(20);
	//second�����һ���սڵ�
	for (auto it = finddata.first; it != finddata.second; it++)
	{
		cout << *it << endl;
	}
	system("pause");
}