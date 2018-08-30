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

//实现链表排序
void sort(ST *head, char ch)
{
	//由大到小循环
	if (ch == '<')
	{
		for (ST *p1 = head; p1 != NULL; p1 = p1->next)
		{
			for (ST *p2 = head; p2 != NULL; p2 = p2->next)
			{
				if (p1->num < p2->num)
				{
					ST temp;//临时变量
					temp.num = p1->num;
					p1->num = p2->num;
					p2->num = temp.num;

					temp.score = p1->score;
					p1->score = p2->score;
					p2->score = temp.score;
				}
			}
		}
	}
	//由小到大循环
	else if (ch == '>')
	{
		for (ST *p1 = head; p1 != NULL; p1 = p1->next)
		{
			for (ST *p2 = head; p2 != NULL; p2 = p2->next)
			{
				if (p1->num > p2->num)
				{
					ST temp;//临时变量
					temp.num = p1->num;
					p1->num = p2->num;
					p2->num = temp.num;

					temp.score = p1->score;
					p1->score = p2->score;
					p2->score = temp.score;
				}
			}
		}
	}
}