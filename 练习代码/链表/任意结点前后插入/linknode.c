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
