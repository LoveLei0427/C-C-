#include<iostream>
#include<set>
#include<stdlib.h>
using namespace std;

int main()
{

	multiset<int>myset; //创建一个包含整数的集合
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(20);
	myset.insert(60);

	//寻找第一个符合的
	auto find1 = myset.find(30);
	cout << *find1 << endl;

	//找到红黑树链表结点 遍历所有元素
	auto finddata = myset.equal_range(20);
	//second是最后一个空节点
	for (auto it = finddata.first; it != finddata.second; it++)
	{
		cout << *it << endl;
	}
	system("pause");
}