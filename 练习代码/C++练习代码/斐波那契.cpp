#include<iostream>
using namespace std;
int main()
{ int i=20;
  int *p=new int[i];			//��������ָ�����p                             
  p[0]=1;						//�����׵�ַ����p
  p[1]=1;
  for(i=2;i<20;i++)
	{p[i]=p[i-1]+p[i-2];}		//����쳲���������ǰ20��
	 for(i=0;i<20;i++)		
	cout<<p[i]<<endl;
	delete p;					//�ͷ�ָ��ָ��Ŀռ�
	return 0;
}