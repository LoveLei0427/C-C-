#include <iostream>
using namespace std;
class book{
	int qu,price;
public:
	book(int x)
	{
		qu = x;
		price = 10*qu;
	}
	void print()
	{	
		cout<<qu<<"*"<<price<<"="<< qu*price<<endl;//计算qu*price
	}
};

int main()
{
	book a[5]={1,2,3,4,5};				  //定义数组并初始化
	cout<<"qu*price的值是:"<<endl;
	for (int i=0;i<5;i++)
	{	
		a[i].print();				 //调用构造函数输出结果
	}
	system("pause");
	return 0;
}
