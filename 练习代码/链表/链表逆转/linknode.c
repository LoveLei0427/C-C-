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
//ʵ����ת
ST *rev(ST *head)
{
	ST *p1, *p2, *p3;
	p1 = p2 = p3 = NULL;
	//����Ϊ�ջ�ֻ��һ�������ֱ�ӷ���ͷ���
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
		//ʵ�ֽ��ͬ��ǰ��
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;//��ʱhead��p1ָ�����һ�����
	return head;//���ں����ĸ������ƣ���Ҫ����ֵ

}