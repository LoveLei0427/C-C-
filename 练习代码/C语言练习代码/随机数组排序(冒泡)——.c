#include<stdio.h>
#define N	10
int main()
{
	int a[N];
	int i = 0,j,temp,temp1;
	printf("������ʮ����:\n");
	for(;i<N;i ++)
	{
		scanf("%d",&a[i]);
	}	
	printf("��ʮ������С����������:\n");
	for (i=0; i<N; i ++)  //���ѭ����ÿѭ��һ�Σ�����ǰ��Сֵ�ϸ�
	{  
		for (j=N-1;j>i;j--)  //�ڲ�ѭ������������������Сֵ�Ƶ�A[i]�� 
		{  
			if (a[j] < a[j-1])//��a[j]<a[j-1]ʱ������Ԫ�ش���ʵ�ֵ�������
			{   
				temp = a[j-1];  
				a[j-1] = a[j];  
				a[j] = temp;  
			}  
		} 
		printf("%-4d",a[i]);
	} 
	printf("\n��ʮ�����ɴ�С������:\n");
	for(i=0;i<N;i++)     
	{
		for(j=N-1;j>i;j--)			
		{
			if (a[j] > a[j-1])			
			{   
				temp1 = a[j];  
				a[j] = a[j-1];  
				a[j-1] = temp1;  
			}	
		}
		printf("%-4d",a[i]);	
	} 
	printf("\n");
	return 0;	
}