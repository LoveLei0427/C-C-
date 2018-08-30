#include<stdio.h>
#include<stdlib.h>
struct INFO
{
	int num;
	struct INFO *p;
};
void main()
{
	//静态创建
	struct INFO info1;
	info1.num = 123;
	struct INFO *p = info1.num;
	printf("%d      %p\n",info1.num, p);
	//动态创建
	struct INFO *pINFO;
	pINFO = (struct INFO *)malloc(sizeof(struct INFO));
	pINFO->num = 125;
	pINFO->p = &(pINFO->num);
	printf("%d      %p\n",pINFO->num, pINFO->p);
	//printf("%d      %p\n", (*pINFO).num, (*pINFO).p);
	system("pause");
}