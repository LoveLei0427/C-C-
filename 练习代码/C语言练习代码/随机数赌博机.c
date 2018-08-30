#include<stdio.h>
#include <time.h>
int main()
{ 			//定义关于时间的函数 time 获取时间保存在ts中
	time_t ts;                      //定义时间数据类型
	srand((unsigned int)time(&ts)); //生成随机数种子
	int num = rand()%100+1;		//取数（0-99）+1
	printf("%d\n",num);
	num > 90 ? printf("你赢了!") : printf("你输了!");
	printf("\n");
	return 0;
}