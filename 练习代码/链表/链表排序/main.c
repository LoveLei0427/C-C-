#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head = NULL;//����ͷ���ָ��
	add(&head, 5, 99);
	add(&head, 6, 80);
	add(&head, 2, 86);
	printf("ѧ��    �ɼ�\n");
	show(head);
	sort(head, '>');
	printf("���������:\n");
	show(head);
	sort(head, '<');
	printf("���������:\n");
	show(head);
	printf("\n");
	system("pause");
}