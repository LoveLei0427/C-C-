//����ģ��������ʽ: template<typename T>��������  ������(ģ���βα�){������}
//�������βο�������ģ��������� ��Ӧʵ���Ǹ���ģ��ʵ������ģ�������
//һ������ӵ����ģ�����ʱ �������Ǻ���ģ��
#include<iostream>
#include<stdlib.h>
using namespace std;
//1
template<typename T>  //ģ������
T max(T x, T y){     //����ģ�嶨�� ����Ϊģ���βα�
	return (x > y) ? x : y;
}
//2
template<typename T>
T sum(T* array, int size = 0){
	T total = 0;
	for (int i = 0; i < size; i++){
		total += array[i];
	}
	return total;
}

int main()
{
	int i1 = 1, i2 = 2;
	char c1 = 'k', c2 = 'j';
	//���ú���ģ�壬i1��i2Ϊģ��ʵ��
	cout << "�ϴ��������:" << max(i1, i2) << endl;
	cout << "�ϴ���ַ���:" << max(c1, c2) << endl;
	cout << "----------------"<< endl;
	int intarray[] = {1,2,3,4,5,6,7,8,9,10};
	double doublearray[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0};
	int intsum = sum(intarray, 10);
	int doublesum = sum(doublearray, 10);
	cout <<"��ʮ�������ĺ���:" << intsum << endl;
	cout << "��ʮ��˫�������ĺ���:" << doublesum << endl;

	system("pause");
	return 0;
}