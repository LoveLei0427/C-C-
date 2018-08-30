/*基类定义的静态成员 被所有派生类共享
派生类中访问静态成员 用以下形式显示说明
类名::成员
对象名.成员
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	static int num; //静态成员变量是共有的被共享 用来统计某各类及派生类对象数目
	int data;
	static void print(){
		cout << "num = " << num << endl;
	}            //脱离对象调用的函数即不实例化就可以调用的函数
	Demo(){
		num++;
	}
};
int Demo::num = 0;

class Demo1 :public Demo{

};

class Demo2 :public Demo1{
	//若此句继承语句为class Demo2:public Demo,public Demo1
	//则以下输出语句结果为4
};

int main(void)
{
	Demo *demo=new Demo;
	Demo1 demo1;
	Demo2 *demo22 = new Demo2;	
	demo->Demo::num;
	demo->print();  //3
	
	demo22->print(); //3
	demo22->Demo2::Demo1::print();//3
	system("pause");
}