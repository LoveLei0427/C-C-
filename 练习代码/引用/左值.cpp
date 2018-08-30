#include<iostream>
#include<stdlib.h>
using namespace std;

//栈上函数
int & get()
{
	int  a = 1; //a存放在栈上 函数调用时分配内存用完时回收
	int ra(a);
	cout << &a << endl;
	return a;
}


//堆上函数--指针
int * & getdata()
{
	int *p;//P在栈上指向堆上内存
	cout << &p;
	p = new int;
	*p = 10;
	int * &rp = p;//引用指针 函数执行完毕后指针释放但是占用 的内存存在
	cout << rp << endl;
	return rp;//返回引用的指针
}




int main(void)
{
	int num1(5);
	int num2(10);
	int *pnum(&num1);

	//左值引用实质是指针实现
	int * &rpnum = pnum;//建立指针变量的引用 int*看做数据类型
	cout<< *pnum <<" "<< *rpnum<< " "<<num2<< " "<< num2<<endl;//5 5 10 5
	
	pnum = &num2;
	cout<< *pnum << " "<< *rpnum<<" "<<num2<<" "<<num2<< endl;//10 10 10 5
	cout<< &pnum <<" "<< &rpnum << " " << &num1 << " " << &num2 << endl;
	cout << "***************" << endl;
	
	int &ra = get();	
	cout << ra << endl;//1	
	cout << "111111" << endl;
	cout << ra << endl;//
	
	cout << "***************" << endl;
	 
	int * &rp = getdata();
	int *prp = rp;
	cout << *rp << endl;//10
	cout << *prp<<endl;//10 因为p在栈上用完释放可以用另一个指针保存堆上地址出费用delete prp

	cout << *rp << endl;//此时rp已释放 溢出

	cout << "***************" << endl;
	int *p;
	p = &num1;//&num1存放在寄存器中
	int * &&rnum = &num1;//&&为引用右值,用于对象拷贝
	p = rnum;
	cout << *p <<*rnum<< endl;//5 5
	system("pause");
}