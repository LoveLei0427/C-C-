/*
�º��� ��������ָ�� ���ýṹ���ڲ�����һ�����ڲ��ĺ���
�º���(functor)������ʹһ�����ʹ�ÿ���ȥ��һ������
*/
#include<iostream>
#include<functional>//������

using namespace std;
using namespace std::placeholders;//ռλ�� ����_1_2�õ�

//�ṹ��������Ƕ����� �����ǹ����
struct Mystruct{
	void add(int a)
	{
		cout << a << endl;
	}
	void add2(int a, int b)
	{
		cout << a + b << endl;
	}

};

int main()
{	
	Mystruct struct1;

	/*�Զ�������������ָ��  ���ȴ��ݽṹ�� �������к���add,����ʵ��struct1���ܹ�һ������
	bind�� (���õ��ڲ��������󶨵�ʵ����󣬲���1������2...)
	����Ԥ�Ȱ�ָ���ɵ���ʵ���ĳЩ�����󶨵����еı���������һ���µĿɵ���ʵ�壬
	��1��bindԤ�Ȱ󶨵Ĳ�����Ҫ������ı�����ֵ��ȥ������Ԥ�Ȱ󶨵Ĳ�������pass-by-value��
    ��2�����ڲ����Ȱ󶨵Ĳ�������Ҫ��std::placeholders��ȥ����_1��ʼ�����ε�����placeholder��pass-by-reference��
    ��3��bind�ķ���ֵ�ǿɵ���ʵ�壬����ֱ�Ӹ���std::function����
    ��4�����ڰ󶨵�ָ�롢�������͵Ĳ�����ʹ������Ҫ��֤�ڿɵ���ʵ�����֮ǰ����Щ�����ǿ��õ�
    ��5�����this����ͨ���������ָ������
	*/
	auto func = bind(&Mystruct::add,&struct1,_1);
	func(100);
	//cin.get();
	cout << endl;
	auto func2 = bind(&Mystruct::add2, &struct1, _1, _2);
	func2(100, 99);
	cin.get();
	/*
	���߸����������ú���
	��������ָ��   ����ͨ��������������
	void (Mystruct::*p)(int a)=&MyStruct::add;

	*/
	getchar();
}