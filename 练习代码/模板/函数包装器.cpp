#include<iostream>  
#include<functional>  
using std::cout;
using std::endl;
using std::cin;
using std::function;


//�������һ��������װ��   T���������� F�Ǻ���
template < typename T, typename F>
T function_wrapper(T t, F fun)
{
	return fun(t);
}
//�������һ��������װ��  
template < typename T, typename F>
T function_wrapper(T t1, T t2, F fun)
{
	static int count = 0;
	count++;
	cout << "������װ��ִ��" << count << "����" << endl;

	return fun(t1, t2);
}
void main()
{

	double d_num = 1.1;
	//double(double)��������������   ��һ��double�Ƿ���ֵ �ڶ���double�Ǻ�������
	//��������Ƕ  
	//�����Ǻ���ָ��  
	// [] ��ʶҪ����һ������  
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