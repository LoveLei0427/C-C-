//node2和node3之间插入node4
#include<stdio.h>
#include<stdlib.h>
struct NODE{
	int num;
	struct NODE *next;
};
void main()
{
	struct NODE node1, node2, node3,*p;
	node1.num = 123;
	node2.num = 456;
	node3.num = 789;   //调用scanf("%d", &node3.num);赋值也可
	struct NODE *head;//创建指针副本保存头结点地址
	head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	struct NODE node4;
	node4.num = 111;
	node4.next = node2.next;
	node2.next = &node4;
	node3.next = NULL;
	p = head;//令p也指向结点node1
	while (p != NULL)
	{
		printf("%d  %p\n", p->num, p->next);
		p = p->next;
	}	
	system("pause");
}