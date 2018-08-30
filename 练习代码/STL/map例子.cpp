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
	
	//打印
	auto ib = maptest.begin();
	auto ie = maptest.end();
	for (; ib != ie; ib++){
		cout << (*ib).first << " " << (*ib).second << endl;
	}   //Beida 3   Qinghua 1  Yanda 2 自动排序输出

	//查找1
	auto find = maptest.find("Yanda");
	//或者使用find->first
	cout << (*find).first << " " << (*find).second<< endl;
	cout << "--------------" << endl;
	//查找2 打印所有关键字为Yangda的数据"
	auto it = maptest.equal_range("Yanda");
	auto p = it.first;
	for (p; p != it.second; p++){
		cout << (*p).first << " " << (*p).second << endl;
	}
	system("pause");
}