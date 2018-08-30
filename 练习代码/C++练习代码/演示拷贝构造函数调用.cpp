#include<iostream>
using namespace std;
class Point	{
public:
	Point (int a0,int b=0);			//�������캯��
	Point (const Point &p);			//�����������캯��
	void print()
	{
		cout<<x<<" "<<y<<endl;
	}
private:
	int x,y;
};
Point::Point(int a,int b)				//���ⶨ�幹�캯��
{
	x=a;
	y=b;
	cout<<"Using normal constructor\n";
}
Point::Point(const Point &p)			//���ⶨ�忽�����캯��
{
	x=2*p.x;
	y=2*p.y;
	cout<<"Using copy constructor\n";

}
void fun1(Point p)						//����fun1���β��������
{
	p.print();
}
Point fun2()							//����fun2�ķ���ֵ�������
{
	Point p4(10,30);					//�������p4��������ͨ���캯��
	return p4;							//���ÿ������캯��
}
int main()
{
	Point p1(30,40);					//����p1ʱ����һ�ε�����ͨ���캯��
	p1.print();
	Point p2(p1);						//����p2ʱ����һ�ε��ÿ������캯��
										//����p1��ʼ������p2
	p2.print();
	Point p3=p1;						//����p3ʱ���ڶ��ε��ÿ������캯��
										//����p1��ʼ������p3
	p3.print();
	fun1(p1);							//���ú���fun1ʱ��ʵ�����βν��ʱ�������ε��ÿ������캯��
	
	p2=fun2();							//����fun2ʱ���ڶ��ε�����ͨ�Ĺ��캯��
										//����fun2����ʱ�����Ĵε��ÿ������캯��

	p2.print();							
	return 0;
}