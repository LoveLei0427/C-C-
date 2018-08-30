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
		printf("%d        %d\n", head->num, head->score);
		head = head->next;
	}
}

//根据指定编号在结点前插入新结点
ST *HeadInsert(ST *head, int num, int newnum,int newscore)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num)
		{
			break;//符合条件时成立
		}
		else
		{
			p2 = p1;//保存当前结点
			p1 = p1->next;//指向下一结点
		}
	}
	if (head == p1)//在头结点前插入
	{
		ST *newnode = (ST *)malloc(sizeof(ST));
		newnode->num = newnum;
		newnode->score = newscore;
		newnode->next = head;
		head = newnode;
	}
	else
	{
		ST *newnode = (ST *)malloc(sizeof(ST));
		newnode->num = newnum;
		newnode->score = newscore;
		newnode->next = p1;
		p2->next = newnode;
	}
	return head;
}
//根据指定编号在结点后插入新结点
ST *BackInsert(ST *head, int num, int newnum, int newscore)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num)
		{
			break;//符合条件时成立
		}
		else
		{
			p1 = p1->next;//指向下一结点
		}
	}
	if (p1 == NULL)//p1若为最后一个结点
	{

		ST *newnode = (ST *)malloc(sizeof(ST));
		newnode->num = newnum;
		newnode->score = newscore;
		newnode->next = NULL;
		p1->next = newnode;
	}
	else
	{
		ST *newnode = (ST *)malloc(sizeof(ST));
		p2 = p1->next;//记录下一结点的位置
		newnode->num = newnum;
		newnode->score = newscore;
		p1->next = newnode;
		newnode->next = p2;
	}
	return head;//没有修改返不返回改head都一样
}