#include<iostream>
using namespace std;
int main()
{ int i=20;
  int *p=new int[i];			//定义整型指针变量p                             
  p[0]=1;						//并将首地址赋给p
  p[1]=1;
  for(i=2;i<20;i++)
	{p[i]=p[i-1]+p[i-2];}		//计算斐波那契数列前20项
	 for(i=0;i<20;i++)		
	cout<<p[i]<<endl;
	delete p;					//释放指针指向的空间
	return 0;
}