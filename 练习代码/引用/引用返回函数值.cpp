#include<iostream>
using namespace std;
int a[]={1,3,5,7,9};
int &index(int);		//������������һ���������͵�����
int main()
{
	index(2)=25;		//���������÷��ڸ�ֵ�������ߣ��ȼ��ڽ���[2]��ֵΪ25
	cout<<index(2)<<endl;//�������Ԫ��a[2]��ֵ
	return 0;
}
int &index(int i)		
{
	return a[i];
}
