#include<iostream>
using std::cout;
using std::endl;

template<typename T>void com(T arg)
{
	arg++;
}

int main(void)
{
	int count(10);
	com(count);	
	cout << count << endl;//10 函数模板 在引用情况下 无效 需使用包装器
	int &rcount(count);
	com(rcount);
	cout << count << endl;//10

	com(std::ref(count));
	cout << count << endl;//11 std::ref是一个函数，返回std::reference_wrapper（类似于指针）
	std::cin.get();
}
