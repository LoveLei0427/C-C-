//字符串“12345”输出整数12345

#include<stdio.h>
#include<stdlib.h>
#define FAUSE -1
int change1(char *str)
{
	char *istr=str;//定义指针保留副本
	int num = 0;
	while (*str != '\0')
	{
		//判断字符是否在0-9之间
		if ((*str<'0')||(*str)>'9')
		{
			return -1;
		}
		str++;
		num++;//计数统计有多少位
	}
	printf("一共有%d位\n", num);
	int res = 0;
	for (int i = 0; i < num; i++)
	{
		res *= 10;				
		int wei = istr[i] - 48;//取出对应字符相应的ASCAII值与48相减依次得到每一位
		res += wei;
		printf("%d", wei);
	}
	return res;//此时res也为25678
}
/*	i	res		wei		res
    	0    	0		2		2
    	1    	20		5		25
	2    	250		6		256
	3    	2560   		7       	2567
	4	25670  		8       	25678
*/
void main()
{
	char str[10] = "25678";
	int i;;
	//通过函数change1改变
	printf("\n调用change2函数:\n");
	change1(str);
	getchar();
}