/*构造函数执行是先父类 后子类  
析构函数是先子类后父类 顺序和构造函数相反*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Demo1{
public:
	Demo1(){ cout << "Creat Demo1111!!!" << endl; }
	~Demo1(){ cout << "Delete Demo111!!!" << endl; }
	void Run(char* str){
		system(str);
	}

};

class Demo2{
public:
	Demo2(){ cout << "Creat Demo222!!!" << endl; }
	~Demo2(){ cout << "Delete Demo222!!!" << endl; }
	int Add(int a, int b){
		return a + b;
	}

};

class Demo :public Demo1, public Demo2{
public:
	Demo(){ cout << "Creat Demo!!!" << endl; }
	~Demo(){ cout << "Delete Demo!!!" << endl; }

};

int main(void){
	Demo demo1;     //Create Demo111!!!  Create Demo222!!! Create Demo!!!
	demo1.Run("calc");
	cout << demo1.Add(1, 2) << endl;
	Demo* p = new Demo; //Create Demo111!!!  Create Demo222!!! Create Demo!!!
	delete p;      //Delete Demo!!! Delete  Demo222!!! Delete  Demo111!!!
	system("pause");
}