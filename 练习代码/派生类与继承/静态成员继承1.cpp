#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	static int num; //��̬��Ա�����ǹ��еı����� ����ͳ����Ŀ
	int data;
	static void print(){
		cout << "num = " << num << endl;
	}
	Demo(){
		num++;
	}
};
int Demo::num = 0;

class Demo1 :public Demo{

};

int main(void)
{
	Demo1 *demo1=new Demo1;
	//Demo1 demo2;��������һ�� �������������2
	//Demo1 *demo3 = new Demo1;��������һ�� �������������3
	demo1->num;
	demo1->print();  //1 ÿ��������󶼻ᴴ��һ���������
	
	demo1->Demo::num;
	demo1->Demo::print(); //1
	system("pause");
}