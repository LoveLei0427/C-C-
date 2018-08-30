//将num为2修改为6
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
ST *Change(ST *head, int oldnum, int newnum)
{
	ST *search = Search(head, oldnum);
	if (search == NULL)
	{
		printf("没有找到相应的数字");
	}
	else
	{
		printf("找到相应的数字,修改成功\n");
		search->num = newnum;
	}
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
	Change(head, 2,6);
	while (head != NULL)
	{
		printf("%d  %p\n", head->num, head->next);
		head = head->next;
	}
	system("pause");
}
/*int getnum(ST *head)
{
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}*/
