#include<iostream>
#include<cmath>
using namespace std;		
int sroot(int i)			 //定义函数sroot
	{
	  return sqrt(i);	
	}					//返回整型的二次方根
long sroot(long l)
	{  
	  return sqrt(l);	
	}					/返回长整的二次方根
double sroot(double d)
	{  
	  return sqrt(d);
	}					//返回双精度数的二次方根
int main()
{
	int i;
	long l;
	double d;
	cin>>i>>l>>d;						//输入i,l,d
	cout<<"i的二次方根是:"<<sroot(i)<<endl;
	cout<<"l的二次方根是:"<<sroot(l)<<endl;
	cout<<"d的二次方根是:"<<sroot(d)<<endl;
	return 0;
}