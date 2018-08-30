#include"linknode.h"

//函数声明，传入头结点地址，并插入数据
void add(ST **phead, int inum, float iscore)
{
	if (*phead == NULL)//判断链表是否为空
	{
		//分配内存并进行初始化
		ST *newnode = (ST*)malloc(sizeof(ST));
		newnode->num = inum;
		newnode->score = iscore;
		newnode->next = NULL;
		*phead = newnode;//让头指针指向新节点
	}
	else
	{//链表不为空时
		ST *p = *phead;//声明指针指向头结点
		while (p->next!= NULL)//循环直到最后一歌结点地址
		{
			p = p->next;
		}
		//若还有新结点，进行尾部插入
		ST *newnode = (ST*)malloc(sizeof(ST));
		newnode->num = inum;
		newnode->score = iscore;
		newnode->next = NULL;
		p->next = newnode;//链接上新结点

	}
}
//传入头结点，显示所有数据
void show(ST *head)
{
	while (head != NULL)//遍历所有结点
	{
		printf("%d      %f\n", head->num, head->score);
		head = head->next;
	}
}
//实现逆转
ST *rev(ST *head)
{
	ST *p1, *p2, *p3;
	p1 = p2 = p3 = NULL;
	//链表为空或只有一个结点则直接返回头结点
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	p1 = head;
	p2 = head->next;
	while (p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		//实现结点同步前移
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;//此时head和p1指向最后一个结点
	return head;//由于函数的副本机制，需要返回值

}