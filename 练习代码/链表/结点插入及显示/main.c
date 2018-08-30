#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head=NULL;//创建头结点指针
	add(&head, 1, 99);
	add(&head, 2, 88);
	add(&head, 3, 86);
	printf("插入结点之前:\n");
	printf("学号   成绩\n");
	show(head);
	head = HeadInsert(head, 2, 6, 100);
	printf("在指定结点前插入新结点:\n");
	printf("学号    成绩\n");
	show(head);
	printf("在指定结点后插入新结点:\n");
	head = BackInsert(head, 3, 9, 77);
	printf("学号    成绩\n");
	show(head);
	printf("\n");
	system("pause");
}