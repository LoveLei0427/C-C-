#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	static int num; //静态成员变量是共有的被共享 用来统计数目
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
	//Demo1 demo2;若是有这一句 则下面结果均输出2
	//Demo1 *demo3 = new Demo1;若是有这一句 则下面结果均输出3
	demo1->num;
	demo1->print();  //1 每个子类对象都会创建一个父类对象
	
	demo1->Demo::num;
	demo1->Demo::print(); //1
	system("pause");
}