//函数指针两种形式

#include<iostream>

int max(int, int);     //1、返回值类型（*函数名）（参数表）
int(*p1)(int, int);

typedef int(*PTR)(int,int);//2、定义新类型PTR返回值是int型 参数是int型
PTR p;					//声明PTR类型变量p


int main(void)
{	
	
	p1 = max;
	(*p1)(1, 2);
	std::cout << std::endl;


	p = max;
	(*p)(10, 19);
	std::cout << std::endl;
	
	std::cin.get();
}


int max(int i, int j)
{
	int temp;
	temp = (i > j ? i : j);
	std::cout << temp;
	return temp;
}

