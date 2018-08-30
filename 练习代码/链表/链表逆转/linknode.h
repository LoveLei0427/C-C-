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

//传入头结点，显示所有数据
void show(ST *head);

//实现链表逆转
ST *rev(ST *head);