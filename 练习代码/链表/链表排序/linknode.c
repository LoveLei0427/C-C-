#include"linknode.h"

//��������������ͷ����ַ������������
void add(ST **phead, int inum, float iscore)
{
	if (*phead == NULL)//�ж������Ƿ�Ϊ��
	{
		//�����ڴ沢���г�ʼ��
		ST *newnode = (ST*)malloc(sizeof(ST));
		newnode->num = inum;
		newnode->score = iscore;
		newnode->next = NULL;
		*phead = newnode;//��ͷָ��ָ���½ڵ�
	}
	else
	{//����Ϊ��ʱ
		ST *p = *phead;//����ָ��ָ��ͷ���
		while (p->next!= NULL)//ѭ��ֱ�����һ�����ַ
		{
			p = p->next;
		}
		//�������½�㣬����β������
		ST *newnode = (ST*)malloc(sizeof(ST));
		newnode->num = inum;
		newnode->score = iscore;
		newnode->next = NULL;
		p->next = newnode;//�������½��

	}
}
//����ͷ��㣬��ʾ��������
void show(ST *head)
{
	while (head != NULL)//�������н��
	{
		printf("%d      %f\n", head->num, head->score);
		head = head->next;
	}
}

//ʵ����������
void sort(ST *head, char ch)
{
	//�ɴ�Сѭ��
	if (ch == '<')
	{
		for (ST *p1 = head; p1 != NULL; p1 = p1->next)
		{
			for (ST *p2 = head; p2 != NULL; p2 = p2->next)
			{
				if (p1->num < p2->num)
				{
					ST temp;//��ʱ����
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
	//��С����ѭ��
	else if (ch == '>')
	{
		for (ST *p1 = head; p1 != NULL; p1 = p1->next)
		{
			for (ST *p2 = head; p2 != NULL; p2 = p2->next)
			{
				if (p1->num > p2->num)
				{
					ST temp;//��ʱ����
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