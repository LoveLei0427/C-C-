
#include<iostream>
using namespace std;
class Building{					//��������Building
protected:
	int floors;
	int rooms;
	double area;
public:
	Building(int f=0,int r=0,double a=0)
	{
		floors=f;
		rooms=r;
		area=a;
	}
	void show1()
	{
		cout<<"¥��������:"<<floors<<"��"<<endl;
		cout<<"��������:"<<rooms<<"��"<<endl;
		cout<<"¥���������:"<<area<<"ƽ����"<<endl;
		cout<<"����:"<<endl;}
};
class house:public Building{				//����house��Ϊ����������
protected:
	int bedrooms;
	int bath;
public:
	house(int f=0,int r=0,double a=0,int b=0,int ba=0):
	  Building(f,r,a)
	  {bedrooms=b;
	  bath=ba;}
	  void show()
	  {
		  cout<<endl;
		  cout<<"סլ¥:"<<endl;
		  Building::show1();
		  cout<<"������"<<bedrooms<<"��"<<endl;
		  cout<<"ԡ����"<<bath<<"��"<<endl;}
};
class office:public Building			//����office��Ϊ����������
{	protected:
int annihilator;
int phone;
public:
	office(int f=0,int r=0,double a=0,int an=0,int p=0):Building(f,r,a)
	{annihilator=an;
	phone=p;
	} 
	void show()
	{cout<<endl;
	cout<<"�칫¥:"<<endl;
	Building::show1();
	cout<<"�������:"<<annihilator<<"��"<<endl;
	cout<<"�绰��:"<<phone<<"̨"<<endl;}
};
int main()
{
	house house1(30,600,50000,160,160);
	office office1(6,120,5000,12,60);
	house1.show();
	office1.show();
	return 0;
}