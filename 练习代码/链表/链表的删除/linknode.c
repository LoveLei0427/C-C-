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

//ɾ������
void freelink(ST *head)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	//��ɾ�����������ɾ��ͷ���
	while (p1->next != NULL)//ѭ���������н��
	{
		p2 = p1->next;
		p1->next = p2->next;
		free(p2);
		printf("\n");
		show(head);
		//ÿ��ѭ������һ��show�����ɲ鿴��ɾ���Ľڵ�
		printf("\n");
	}
	free(head);//�ͷ�ͷ���
}