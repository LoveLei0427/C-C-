//��ָ�������Լ�malloc free��new delete
#include<iostream>
#include<stdlib.h>
using namespace std;
class Demo{
public:
	int x;
	int y;
	//Demo(){ 
	//	cout << "Hello!!!" << endl; 
	//}
	//~Demo(){
	//	cout << "ByeBye!!!" << endl;
	//}
	Demo(int, int);
	void printXY();
};

Demo demo(6, 6);
Demo testptr1(99, 99);
Demo testptr2(100, 100);
Demo::Demo(int a, int b) :x(a), y(b){}

void Demo::printXY(){
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

}
//����ָ��
void changeptr1(Demo** ptr){

	*ptr = &testptr1;
}

//����
void changeptr2(Demo* &ptr){
	ptr = &testptr2;
}
int main(void)
{
	Demo* demo1 = new Demo(1,2);//Demo* demo1(new Demo());
	demo1->printXY();  //x=1 y=2
	//new����ʹ��deleteɾ��ʱ �Զ����ù�����������
	//Demo *demo1=(Demo*)malloc(sizeof(Demo)); 
	//malloc������ֻ������ڴ治����в��� ��free����ʱ ���������������

	Demo  demo2(10, 20); 
	demo2.printXY();  //x=10 y =20
	
	Demo** demo3 = &demo1; //����ָ����һ��ָ��ĵ�ַ
	(*demo3)->printXY(); //x=1 y=2  һ��ָ��
	(**demo3).printXY();//x=1 y=2   �㼶ָ��

	demo1 = &demo;
	demo1->printXY();   // 6 6
	
	//�ı�ָ��ָ���
	cout << "�ı�ָ��ָ���" << endl;
	changeptr1(&demo1);
	demo1->printXY();   //99 99

	changeptr2(demo1);
	demo1->printXY();   // 100 100
	system("pause");
}