#include<iostream>
#include<bitset>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	//��ʮ������255ת��Ϊ8λ�Ķ�����
	bitset<8>bb(255);
	for (int i = 7; i >=0; i--){
		cout << bb[i]<<endl; //�������
	}
	//����i=0;i<8;i++ �����������
	system("pause");
}