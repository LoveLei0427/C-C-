#include<stdio.h>
#define N	10
int main()
{
	int a[N];
	int i = 0,j,temp,temp1;
	printf("请输入十个数:\n");
	for(;i<N;i ++)
	{
		scanf("%d",&a[i]);
	}	
	printf("这十个数由小到大排列是:\n");
	for (i=0; i<N; i ++)  //外层循环，每循环一次，将当前最小值上浮
	{  
		for (j=N-1;j>i;j--)  //内层循环，反复交换，将最小值移到A[i]处 
		{  
			if (a[j] < a[j-1])//当a[j]<a[j-1]时，交换元素次序，实现递增排序
			{   
				temp = a[j-1];  
				a[j-1] = a[j];  
				a[j] = temp;  
			}  
		} 
		printf("%-4d",a[i]);
	} 
	printf("\n这十个数由大到小排列是:\n");
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