
#include<stdio.h>
#include<math.h>
int main(){
	double f(double x);
	double Abs(double x);
	int k = 0;					 //记录次数
	double y1,y2,y;
	double a,b,x1,x2,x0;        //定义端点值，x0,允许误差,y值
	printf("请输入区间左右端点a,b值:");
	scanf("%lf%lf",&a,&b);
	printf("请输入允许误差值x1,  x2:");
	scanf("%lf%lf",&x1,&x2);
	y1 = f(a);
	y2 = f(b);
	if(y1*y2>0)                       //判断端点值
	{
		printf("错误的解区间");	
	}
	else {								 //循环控制中点的位置
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
		printf("共执行%d次\n方程解是%lf\nf(x0)的值是%lf\n",k,x0,y);
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
double  f(double x)    		//定义函数，并用实例验证
{
	return 6*x*x-36;
}
