#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"

void main6()
{
	struct student *head = NULL;//����ͷ���ָ��
	add(&head, 5, 99);
	add(&head, 6, 80);
	add(&head, 2, 86);
	int num = getnum(head);
	printf("%d",num);
	printf("\n");
	system("pause");
}