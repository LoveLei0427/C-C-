#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"
void main()
{
	struct student *head=NULL;//����ͷ���ָ��
	add(&head, 1, 99);
	add(&head, 2, 88);
	add(&head, 3, 86);
	printf("������֮ǰ:\n");
	printf("ѧ��   �ɼ�\n");
	show(head);
	head = HeadInsert(head, 2, 6, 100);
	printf("��ָ�����ǰ�����½��:\n");
	printf("ѧ��    �ɼ�\n");
	show(head);
	printf("��ָ����������½��:\n");
	head = BackInsert(head, 3, 9, 77);
	printf("ѧ��    �ɼ�\n");
	show(head);
	printf("\n");
	system("pause");
}