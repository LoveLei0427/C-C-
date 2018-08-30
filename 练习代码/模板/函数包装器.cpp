#include<iostream>  
#include<functional>  
using std::cout;
using std::endl;
using std::cin;
using std::function;


//定义好了一个函数包装器   T是数据类型 F是函数
template < typename T, typename F>
T function_wrapper(T t, F fun)
{
	return fun(t);
}
//定义好了一个函数包装器  
template < typename T, typename F>
T function_wrapper(T t1, T t2, F fun)
{
	static int count = 0;
	count++;
	cout << "函数包装器执行" << count << "次数" << endl;

	return fun(t1, t2);
}
void main()
{

	double d_num = 1.1;
	//double(double)是声明函数类型   第一个double是返回值 第二个double是函数参数
	//允许函数内嵌  
	//本质是函数指针  
	// [] 标识要开辟一个函数  
	function<double(double)> square_fun = [](double in_data)
	{
		return in_data*in_data;
	};
	//  
	function<double(double)> cube_fun = [](double in_data)
	{
		return in_data*in_data*in_data;
	};
	function<int(int, int)> add_fun = [](int in_data1, int in_data2)
	{
		return in_data1 + in_data2;
	};
	cout << function_wrapper(d_num, square_fun) << " " << function_wrapper(d_num, cube_fun) << endl;
	cout << function_wrapper(1, 2, add_fun) << endl;
	cin.get();
}