#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	struct student *next; //�洢��һ�����ĵ�ַ
};

//��д�ṹ������
typedef struct student ST;

int getnum(ST *head)
{
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}
void main()
{
	ST node1, node2, node3;
	node1.num = 1;
	node2.num = 2;
	node3.num = 3;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	ST *head = &node1;
	int num = getnum(head);
	printf("%d", num);
	printf("\n");
	system("pause");
}