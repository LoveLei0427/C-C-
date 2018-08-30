#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head = NULL;//创建头结点指针
	add(&head, 5, 99);
	add(&head, 6, 80);
	add(&head, 2, 86);
	printf("学号    成绩\n");
	show(head);
	sort(head, '>');
	printf("链表排序后:\n");
	show(head);
	sort(head, '<');
	printf("链表排序后:\n");
	show(head);
	printf("\n");
	system("pause");
}