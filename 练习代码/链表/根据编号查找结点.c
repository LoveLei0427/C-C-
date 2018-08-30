#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	struct student *next; //存储下一个结点的地址
};

//简写结构体声明
typedef struct student ST;
//根据编号查找结点
ST *Search(ST *head, int num)
{
	while (head != NULL)//循环遍历链表
	{
		if (num == head->num)
		{
			printf("找到对应结点");
			return head;//返回结点指针
		}
		head = head->next;
	}
	return NULL;
}
void main()
{
	ST node1, node2, node3;
	node1.num = 1;
	node2.num = 2;
	node3.num = 3;
	ST *head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	ST *search = Search(head, 3);
	printf("%d\n",search->num);
	system("pause");
}