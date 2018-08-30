/*
联编是程序模块 代码之间相互关联的过程
静态联编是程序的匹配、连接在编译阶段实现---重载函数
动态联编是运行时编译--switch和if语句
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Demo1{
public:
	void Run(){
		cout << "Run_Demo1!" << endl;
	}
	void Run(int num){
		cout << "RunInt_Demo1!" << num << endl;
	}
	void Run(char* str){
		cout << "RunStr_Demo1!" << str << endl;
	}
};

class Demo2 :public Demo1{
public:
	void Run(){
		cout << "Run_Demo2!" << endl;
	}
};


int main(void)
{
	Demo2* ptr = new Demo2;
	ptr->Run();  //Run_Demo2!
	
	
	//父类与子类之间的重载同名函数会覆盖 即使参数类型不同不能直接调用
	//必须调用父类默认生成的对象调用
	//ptr->Run(nullptr);//错误,函数不接受一个参数
	ptr->Demo1::Run(NULL); //RunInt_Demo1!  0
	//ptr->Demo1::Run(nullptr);//C++空指针无法打印 可以调用但是打印出错

	system("pause");
}