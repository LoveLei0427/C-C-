//�ɱ��������ģ��ͨ���ǵݹ�ġ���һ�����ô�����еĵ�һ��ʵ�Σ�Ȼ����ʣ���ʵ�ε�������Ϊ����ֹ�ݹ飬���ǻ���Ҫ����һ���ǿɱ�����ĺ���ģ��
#include<iostream>
#include<vector>
#include<string>
void show(){}//�պ��� Ԥ���ӿ����� ����ȥ
template<class T, class...Args>void show(T value, Args...rest)
{
	std::cout << value << std::endl;
	show(rest...);//��������

} 

int main(void)
{ 
	
	int a = 10, b = 20, c = 15;
	double i = 1.1, j = 20.1;
	std::string s = "hello";
	show(a, b, c);
	show(a, i, s);
	std::cin.get();
}