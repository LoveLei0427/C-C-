#include<stdio.h>
#define N 10
int main()
{	
	int a[N];
	int i,j;	
	int temp;				//�����Сֵ  
	int pos;				//�����Сֵ���±�  
	printf("������10����:\n");
	for(i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
						  
	for (i=0; i<N-1; i++)	//���ѭ����ÿһ��ѭ������Сֵ���뵽λ��i
	{  
		temp = a[i];		//��ʼ��
		pos = i;  
		for (j=i+1; j<N; j++)  //�ڲ�ѭ�����ҳ���Сֵ  
		{  
			if (a[j] < temp)  //�ҳ���Сֵ  
			{  
				temp = a[j];  
				pos = j;  
			}  
		}  		 
		a[pos] = a[i];		//����СԪ���뵱ǰλ��Ԫ�ؽ��� 
		a[i] = temp;  
	}  
	for(i = 0;i < N;i++)
	{
		printf("%d\n",a[i]);
	}
} 