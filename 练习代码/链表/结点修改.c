//��numΪ2�޸�Ϊ6
#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	struct student *next; //�洢��һ�����ĵ�ַ
};

//��д�ṹ������
typedef struct student ST;
//���ݱ�Ų��ҽ��
ST *Search(ST *head, int num)
{
	while (head != NULL)//ѭ����������
	{
		if (num == head->num)
		{
			printf("�ҵ���Ӧ���");
			return head;//���ؽ��ָ��
		}
		head = head->next;
	}
	return NULL;
}
ST *Change(ST *head, int oldnum, int newnum)
{
	ST *search = Search(head, oldnum);
	if (search == NULL)
	{
		printf("û���ҵ���Ӧ������");
	}
	else
	{
		printf("�ҵ���Ӧ������,�޸ĳɹ�\n");
		search->num = newnum;
	}
}
void main()
{
	ST node1, node2, node3;
	node1.num = 1;
	node2.num = 2;
	node3.num = 3;
	ST *head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	Change(head, 2,6);
	while (head != NULL)
	{
		printf("%d  %p\n", head->num, head->next);
		head = head->next;
	}
	system("pause");
}
/*int getnum(ST *head)
{
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}*/
