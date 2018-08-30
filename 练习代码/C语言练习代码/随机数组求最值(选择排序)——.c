#include<stdio.h>
#define N 10
int main()
{	
	int a[N];
	int i,j;	
	int temp;				//存放最小值  
	int pos;				//存放最小值的下标  
	printf("请输入10个数:\n");
	for(i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
						  
	for (i=0; i<N-1; i++)	//外层循环，每一次循环将最小值放入到位置i
	{  
		temp = a[i];		//初始化
		pos = i;  
		for (j=i+1; j<N; j++)  //内层循环，找出最小值  
		{  
			if (a[j] < temp)  //找出最小值  
			{  
				temp = a[j];  
				pos = j;  
			}  
		}  		 
		a[pos] = a[i];		//将最小元素与当前位置元素交换 
		a[i] = temp;  
	}  
	for(i = 0;i < N;i++)
	{
		printf("%d\n",a[i]);
	}
} 