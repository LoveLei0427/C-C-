#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head=NULL;//����ͷ���ָ��
	add(&head, 1, 99);
	add(&head, 2, 88);
	add(&head, 3, 86);
	printf("ѧ��    �ɼ�\n");
	show(head);
	/*printf("ɾ�������:\n\n");
	printf("ѧ��    �ɼ�\n");*/
	freelink(head);
	head = NULL;
	show(head);
	printf("\n");
	system("pause");
}