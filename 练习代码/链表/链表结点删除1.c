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
	struct NODE *head;//����ָ�븱������ͷ����ַ
	head = &node1;
	node1.next = &node3;   //ֱ����node1����һ����ַ��Ϊnode3�ĵ�ַ����
	//node2.next = &node3;
	node3.next = NULL;
	p = head;	//��pҲָ����node1
	while (p != NULL)
	{
		printf("%d  %p\n", p->num, p->next);
		p = p->next;
	}	
	system("pause");
}