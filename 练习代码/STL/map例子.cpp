#include<iostream>
#include<map>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	multimap<string, int>maptest;
	maptest.insert(pair<string,int>("Qinghua",1));
	maptest.insert(pair<string, int>("Beida", 3));
	maptest.insert(pair<string, int>("Yanda", 2));
	maptest.insert(pair<string, int>("Yanda", 4));
	maptest.insert(pair<string, int>("Yanda", 5));
	
	//��ӡ
	auto ib = maptest.begin();
	auto ie = maptest.end();
	for (; ib != ie; ib++){
		cout << (*ib).first << " " << (*ib).second << endl;
	}   //Beida 3   Qinghua 1  Yanda 2 �Զ��������

	//����1
	auto find = maptest.find("Yanda");
	//����ʹ��find->first
	cout << (*find).first << " " << (*find).second<< endl;
	cout << "--------------" << endl;
	//����2 ��ӡ���йؼ���ΪYangda������"
	auto it = maptest.equal_range("Yanda");
	auto p = it.first;
	for (p; p != it.second; p++){
		cout << (*p).first << " " << (*p).second << endl;
	}
	system("pause");
}