#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head=NULL;//创建头结点指针
	add(&head, 1, 99);
	add(&head, 2, 88);
	add(&head, 3, 86);
	printf("学号    成绩\n");
	show(head);
	head=rev(head);
	printf("链表逆转后:\n");
	show(head);
	printf("\n");
	system("pause");
}