/*��ģ���ⶨ���Ա������ʽ��
template<typename ���Ͳ���>
��������  ����<���Ͳ���>::��Ա������(�βα�)
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>    //ģ������
class Compare{        //����ģ�嶨�� ����Ϊģ���βα�
public:
	Compare(T a,T b);
	T max();
private:
	T x, y;
};

template<typename T>
Compare<T>::Compare(T a, T b){
	x = a;
	y = b;
}
template<typename T>
T Compare<T>::max(){
	return (x > y) ? x : y;
}

int main()
{
	Compare<int>c1(1, 2);
	cout << "�ϴ��ֵ��:" <<c1.max()<< endl;
	system("pause");
	return 0;
}