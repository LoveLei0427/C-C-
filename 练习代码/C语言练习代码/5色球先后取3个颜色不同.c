#include<stdio.h>
int main()
{
	enum Color{red,yellow,blue,white,black};	//声明枚举类型enum Color
	enum Color i,j,k,pri;						//定义枚举类型 i,j,k,pri
	int n,loop;		
	n=0;
	for(i=red;i<=black;i++)					    //外循环使i的值变化
		for(j=red;j<=black;j++)				    //中循环使j的值变化
			if(i!=j)						    //二球不同色
			{
				for(k=red;k<=black;k++)		    //内循环使k的值变化
					if((k!=i)&&(k!=j))
					{
						n=n+1;
						printf("%4d",n);
						for(loop=1;loop<=3;loop++)  //先后对三个球处理
						{
							switch(loop)
							{
							case 1: pri=i;break;    //loop值为1时,第一球的颜色给pri
							case 2: pri=j;break;
							case 3: pri=k;break;
							default : break;
							}
							switch(pri)				//根据球的颜色输出相应文字
							{
							case red:printf("%-10s","red"); break; 
								//pri的值等于枚举常量red时输出"red"
							case yellow:printf("%-10s","yellow"); break;
							case blue:printf("%-10s","blue"); break;
							case white:printf("%-10s","white"); break;
							case black:printf("%-10s","black"); break;
							default: break;
							}
						}
						printf("\n");
					}
			}
			printf("\ntotal:%5d\n",n);
			return 0;
}