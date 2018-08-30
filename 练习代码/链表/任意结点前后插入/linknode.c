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
