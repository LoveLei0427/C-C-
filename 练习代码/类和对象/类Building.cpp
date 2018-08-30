
#include<iostream>
using namespace std;
class Building{					//声明基类Building
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
		cout<<"楼房层数是:"<<floors<<"层"<<endl;
		cout<<"房间数是:"<<rooms<<"间"<<endl;
		cout<<"楼房总面积是:"<<area<<"平方米"<<endl;
		cout<<"其中:"<<endl;}
};
class house:public Building{				//声明house作为共有派生类
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
		  cout<<"住宅楼:"<<endl;
		  Building::show1();
		  cout<<"卧室数"<<bedrooms<<"间"<<endl;
		  cout<<"浴室数"<<bath<<"间"<<endl;}
};
class office:public Building			//声明office作为共有派生类
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
	cout<<"办公楼:"<<endl;
	Building::show1();
	cout<<"灭火器有:"<<annihilator<<"个"<<endl;
	cout<<"电话有:"<<phone<<"台"<<endl;}
};
int main()
{
	house house1(30,600,50000,160,160);
	office office1(6,120,5000,12,60);
	house1.show();
	office1.show();
	return 0;
}