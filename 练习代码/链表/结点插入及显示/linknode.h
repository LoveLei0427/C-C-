#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	int score;
	struct student *next; //�洢��һ�����ĵ�ַ
};

//��д�ṹ������
typedef struct student ST;

//��������������ͷ����ַ������������
void add(ST **phead,int inum,float iscore);

//����ͷ��㣬��ʾ��������
void show(ST *head);

//����ָ������ڽ��ǰ/������½��
ST *HeadInsert(ST *head, int num, int newnum);

//����ָ������ڽ�������½��
ST *BackInsert(ST *head, int num, int newnum, int newscore);