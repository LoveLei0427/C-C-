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

//ͳ�ƽ�����
int getnum(ST *head);