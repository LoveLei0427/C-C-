#include<iostream>
#define Pi 3.14
using namespace std;
class Cylinder{							//声明类Cylinder
   public:
	 Cylinder(double i,double j)		//共有成员函数，为r,h赋值
	 {r=i;
	  h=j;
	 }
	 double vo1()						//成员函数计算体积					
	 {double V;
	  V=Pi*r*r*h;
	  return (V);
	 }
    private:							
	 double r;								
	 double h;
};
int main()
{	double m,n;
	cout<<"输入半径和柱体高度:"<<endl;
	cin>>m;
	cin>>n;
	Cylinder X(m,n);					 //声明对象X
	cout<<"圆柱体体积是:"<<X.vo1()<<endl;//调用成员函数,输出程序结果
	return 0;
}