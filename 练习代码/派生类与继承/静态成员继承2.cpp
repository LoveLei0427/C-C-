/*���ඨ��ľ�̬��Ա �����������๲��
�������з��ʾ�̬��Ա ��������ʽ��ʾ˵��
����::��Ա
������.��Ա
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	static int num; //��̬��Ա�����ǹ��еı����� ����ͳ��ĳ���༰�����������Ŀ
	int data;
	static void print(){
		cout << "num = " << num << endl;
	}            //���������õĺ�������ʵ�����Ϳ��Ե��õĺ���
	Demo(){
		num++;
	}
};
int Demo::num = 0;

class Demo1 :public Demo{

};

class Demo2 :public Demo1{
	//���˾�̳����Ϊclass Demo2:public Demo,public Demo1
	//��������������Ϊ4
};

int main(void)
{
	Demo *demo=new Demo;
	Demo1 demo1;
	Demo2 *demo22 = new Demo2;	
	demo->Demo::num;
	demo->print();  //3
	
	demo22->print(); //3
	demo22->Demo2::Demo1::print();//3
	system("pause");
}