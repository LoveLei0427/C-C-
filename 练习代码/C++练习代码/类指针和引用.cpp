//类指针引用以及malloc free与new delete
#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	int x;
	int y;
	//Demo(){ 
	//	cout << "Hello!!!" << endl; 
	//}
	//~Demo(){
	//	cout << "ByeBye!!!" << endl;
	//}
	Demo(int, int);
	void printXY();
};

Demo demo(6, 6);
Demo testptr1(99, 99);
Demo testptr2(100, 100);
Demo::Demo(int a, int b) :x(a), y(b){}

void Demo::printXY(){
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

}
//二级指针
void changeptr1(Demo** ptr){

	*ptr = &testptr1;
}

//引用
void changeptr2(Demo* &ptr){
	ptr = &testptr2;
}
int main(void)
{
	Demo* demo1 = new Demo(1,2);//Demo* demo1(new Demo());
	demo1->printXY();  //x=1 y=2
	//new声明使用delete删除时 自动调用构造析构函数
	//Demo *demo1=(Demo*)malloc(sizeof(Demo)); 
	//malloc声明的只会分配内存不会进行操作 用free销毁时 不会调用析构函数

	Demo  demo2(10, 20); 
	demo2.printXY();  //x=10 y =20
	
	Demo** demo3 = &demo1; //二级指针存放一级指针的地址
	(*demo3)->printXY(); //x=1 y=2  一级指针
	(**demo3).printXY();//x=1 y=2   零级指针

	demo1 = &demo;
	demo1->printXY();   // 6 6
	
	//改变指针指向后
	cout << "改变指针指向后" << endl;
	changeptr1(&demo1);
	demo1->printXY();   //99 99

	changeptr2(demo1);
	demo1->printXY();   // 100 100
	system("pause");
}