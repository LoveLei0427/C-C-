#include<stdio.h>
int main()
{
	enum Color{red,yellow,blue,white,black};	//����ö������enum Color
	enum Color i,j,k,pri;						//����ö������ i,j,k,pri
	int n,loop;		
	n=0;
	for(i=red;i<=black;i++)					    //��ѭ��ʹi��ֵ�仯
		for(j=red;j<=black;j++)				    //��ѭ��ʹj��ֵ�仯
			if(i!=j)						    //����ͬɫ
			{
				for(k=red;k<=black;k++)		    //��ѭ��ʹk��ֵ�仯
					if((k!=i)&&(k!=j))
					{
						n=n+1;
						printf("%4d",n);
						for(loop=1;loop<=3;loop++)  //�Ⱥ����������
						{
							switch(loop)
							{
							case 1: pri=i;break;    //loopֵΪ1ʱ,��һ�����ɫ��pri
							case 2: pri=j;break;
							case 3: pri=k;break;
							default : break;
							}
							switch(pri)				//���������ɫ�����Ӧ����
							{
							case red:printf("%-10s","red"); break; 
								//pri��ֵ����ö�ٳ���redʱ���"red"
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