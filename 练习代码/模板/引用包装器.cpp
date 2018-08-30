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
	cout << count << endl;//10 ����ģ�� ����������� ��Ч ��ʹ�ð�װ��
	int &rcount(count);
	com(rcount);
	cout << count << endl;//10

	com(std::ref(count));
	cout << count << endl;//11 std::ref��һ������������std::reference_wrapper��������ָ�룩
	std::cin.get();
}
