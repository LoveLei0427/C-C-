#include<stdio.h>
#include<stdlib.h>
struct student{
	int num;
	float score;
	struct student *next; //�洢��һ�����ĵ�ַ
};

//��д�ṹ������
typedef struct student ST;

//��������������ͷ����ַ������������
void add(ST **phead,int inum,float iscore);

//����ͷ��㣬��ʾ��������
void show(ST *head);

//ʵ��������ת
ST *rev(ST *head);