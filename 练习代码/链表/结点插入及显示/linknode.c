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
		printf("%d        %d\n", head->num, head->score);
		head = head->next;
	}
}

//����ָ������ڽ��ǰ�����½��
ST *HeadInsert(ST *head, int num, int newnum,int newscore)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num)
		{
			break;//��������ʱ����
		}
		else
		{
			p2 = p1;//���浱ǰ���
			p1 = p1->next;//ָ����һ���
		}
	}
	if (head == p1)//��ͷ���ǰ����
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
//����ָ������ڽ�������½��
ST *BackInsert(ST *head, int num, int newnum, int newscore)
{
	ST *p1, *p2;
	p1 = p2 = NULL;
	p1 = head;
	while (p1 != NULL)
	{
		if (p1->num == num)
		{
			break;//��������ʱ����
		}
		else
		{
			p1 = p1->next;//ָ����һ���
		}
	}
	if (p1 == NULL)//p1��Ϊ���һ�����
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
		p2 = p1->next;//��¼��һ����λ��
		newnode->num = newnum;
		newnode->score = newscore;
		p1->next = newnode;
		newnode->next = p2;
	}
	return head;//û���޸ķ������ظ�head��һ��
}