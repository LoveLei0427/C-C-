#include<iostream>
#define Pi 3.14
using namespace std;
class Cylinder{							//������Cylinder
   public:
	 Cylinder(double i,double j)		//���г�Ա������Ϊr,h��ֵ
	 {r=i;
	  h=j;
	 }
	 double vo1()						//��Ա�����������					
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
	cout<<"����뾶������߶�:"<<endl;
	cin>>m;
	cin>>n;
	Cylinder X(m,n);					 //��������X
	cout<<"Բ���������:"<<X.vo1()<<endl;//���ó�Ա����,���������
	return 0;
}