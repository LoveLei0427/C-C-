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
		cout<<qu<<"*"<<price<<"="<< qu*price<<endl;//����qu*price
	}
};

int main()
{
	book a[5]={1,2,3,4,5};				  //�������鲢��ʼ��
	cout<<"qu*price��ֵ��:"<<endl;
	for (int i=0;i<5;i++)
	{	
		a[i].print();				 //���ù��캯��������
	}
	system("pause");
	return 0;
}
