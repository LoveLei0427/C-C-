
#include<stdio.h>
#include<math.h>
int main(){
	double f(double x);
	double Abs(double x);
	int k = 0;					 //��¼����
	double y1,y2,y;
	double a,b,x1,x2,x0;        //����˵�ֵ��x0,�������,yֵ
	printf("�������������Ҷ˵�a,bֵ:");
	scanf("%lf%lf",&a,&b);
	printf("�������������ֵx1,  x2:");
	scanf("%lf%lf",&x1,&x2);
	y1 = f(a);
	y2 = f(b);
	if(y1*y2>0)                       //�ж϶˵�ֵ
	{
		printf("����Ľ�����");	
	}
	else {								 //ѭ�������е��λ��
		x0 = (a+b)/2;
		y = f(x0);
		for(;Abs(y)>=x1;){
			k++;
			x0 = (a+b)/2;
			y = f(x0);
			if(y1*y<0){
				b = x0;
			}
			else {
				a = x0;
				y1 = y; 	
			}
			if(b-a<x2)break;
			
		}
		printf("��ִ��%d��\n���̽���%lf\nf(x0)��ֵ��%lf\n",k,x0,y);
	}
	return 0;
}
double Abs(double x)
{
	if(x>0) 
		return x;
	else 
		return -x;
	
}
double  f(double x)    		//���庯��������ʵ����֤
{
	return 6*x*x-36;
}
