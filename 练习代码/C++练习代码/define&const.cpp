#include<iostream>
using namespace std;
int main(void)
{
	int a = 1;
	#define A1 a+a
	#define A2 A1-A1
	cout << "A2 is " << A2 << endl;		//����Ϊ a + a - a + a = 2
	int b = 2;
	const int B1 = b + b;
	const int B2 = B1 - B1;			//����Ϊ 2b - 2b = 0 
	cout << "B2 is " << B2 << endl;
	system("pause");
}