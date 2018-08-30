#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	float score;
	struct student *next; //存储下一个结点的地址
};

//简写结构体声明
typedef struct student ST;

//函数声明，传入头结点地址，并插入数据
void add(ST **phead,int inum,float iscore);

//统计结点个数
int getnum(ST *head);