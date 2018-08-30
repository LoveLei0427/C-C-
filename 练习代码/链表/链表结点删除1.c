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
	node3.num = 789;   
	struct NODE *head;//创建指针副本保存头结点地址
	head = &node1;
	node1.next = &node3;   //直接令node1的下一个地址改为node3的地址即可
	//node2.next = &node3;
	node3.next = NULL;
	p = head;	//令p也指向结点node1
	while (p != NULL)
	{
		printf("%d  %p\n", p->num, p->next);
		p = p->next;
	}	
	system("pause");
}