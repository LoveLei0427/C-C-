/*
�����ǳ���ģ�� ����֮���໥�����Ĺ���
��̬�����ǳ����ƥ�䡢�����ڱ���׶�ʵ��---���غ���
��̬����������ʱ����--switch��if���
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Demo1{
public:
	void Run(){
		cout << "Run_Demo1!" << endl;
	}
	void Run(int num){
		cout << "RunInt_Demo1!" << num << endl;
	}
	void Run(char* str){
		cout << "RunStr_Demo1!" << str << endl;
	}
};

class Demo2 :public Demo1{
public:
	void Run(){
		cout << "Run_Demo2!" << endl;
	}
};


int main(void)
{
	Demo2* ptr = new Demo2;
	ptr->Run();  //Run_Demo2!
	
	
	//����������֮�������ͬ�������Ḳ�� ��ʹ�������Ͳ�ͬ����ֱ�ӵ���
	//������ø���Ĭ�����ɵĶ������
	//ptr->Run(nullptr);//����,����������һ������
	ptr->Demo1::Run(NULL); //RunInt_Demo1!  0
	//ptr->Demo1::Run(nullptr);//C++��ָ���޷���ӡ ���Ե��õ��Ǵ�ӡ����

	system("pause");
}