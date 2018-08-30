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

//删除链表
void freelink(ST *head)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	//先删除其余结点最后删除头结点
	while (p1->next != NULL)//循环遍历所有结点
	{
		p2 = p1->next;
		p1->next = p2->next;
		free(p2);
		printf("\n");
		show(head);
		//每次循环调用一次show函数可查看被删除的节点
		printf("\n");
	}
	free(head);//释放头结点
}