#include<iostream>
using namespace std;
int main()
{
	//动态分配整型存储空间并赋值
	int *p1;
	p1 = new int;
	if (!p1)
	{
		cout << "Allocation Failure" << endl;
		return 1;
	}
	*p1 = 100;
	cout << *p1 << endl;  //100
	delete p1;			//必需且仅需释放一次

	//为一维数组分配空间
	char *p2 = new char[5];
	p2[0] = 'L';
	p2[1] = 'o';
	p2[2] = 'v';
	p2[3] = 'e';
	p2[4] = '\0';		//要以'\0'结尾否则会越界乱码
	cout << p2 << endl;  //Love
	delete[] p2;

	//二维数组分配内存
	int **p3;
	p3 = new int*[3];		//开辟大小为3的指向int型的指针
	//p3相当于数组首地址

	for (int i = 0; i < 3; i++)
	{
		p3[i] = new int[4];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			p3[i][j] = i + j;
			cout << ' ' << p3[i][j];   // 0 1 2 3
		}                              // 1 2 3 4
		cout << endl;                  // 2 3 4 5
	}
	for (int i = 0; i < 3; i++)
	{
		delete[]p3[i];
	}
	delete[]p3;

	//分配内存的同时初始化，不适用动态分配的数组存储区
	int *p4 = new int(99);
	cout << *p4 << endl;                       //99
	delete p4;

	system("pause");
}