#include<iostream>
#include<cmath>
using namespace std;		
int sroot(int i)			 //���庯��sroot
	{
	  return sqrt(i);	
	}					//�������͵Ķ��η���
long sroot(long l)
	{  
	  return sqrt(l);	
	}					/���س����Ķ��η���
double sroot(double d)
	{  
	  return sqrt(d);
	}					//����˫�������Ķ��η���
int main()
{
	int i;
	long l;
	double d;
	cin>>i>>l>>d;						//����i,l,d
	cout<<"i�Ķ��η�����:"<<sroot(i)<<endl;
	cout<<"l�Ķ��η�����:"<<sroot(l)<<endl;
	cout<<"d�Ķ��η�����:"<<sroot(d)<<endl;
	return 0;
}