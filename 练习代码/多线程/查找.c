#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >

struct Mystruct{
	int *startaddress;//Ҫ���ҵ��׵�ַ
	int length;		  //�޶�����
	int *pflag;		  //Ϊ0��ʾ�ҵ�������֪ͨ�����̴߳���flag��ַ
	int num;		 //Ҫ���ҵ�����
	int bh;			//������ڱ���߳�
};
typedef struct Mystruct	M;
void find(void *p)
{
	M *pstruct = (M *)p;
	//�ڴ����ݵı������ӿ�ʼ�ۼ�100��Ԫ��
	for (int *px = pstruct->startaddress; px < pstruct->startaddress+100; px++)
	{
		if (*px == pstruct->num)//�ж��Ƿ��ҵ�����
		{
			printf("******��%d���߳��ҵ�******%p,%d\n", pstruct->bh,px, *px);
			return;
		}
	}
	printf("��%d���߳���û���ҵ���\n",pstruct->bh);
}
void main()
{
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{

		a[i] = i;
	}
	//����10���߳�
	for (int j = 0; j < 10; j++)
	{
		//��ַΪa a+100 a+200...
		int *p = a + j * 100;
		M threaddata;//�����ṹ��
		threaddata.startaddress = p;
		threaddata.length = 100;//�޶�����
		threaddata.bh = j;
		threaddata.num = 668;
		threaddata.pflag = NULL;
		_beginthread(find, 0, &threaddata);
		Sleep(10);
		//Windows���̲߳�������ȫ��ʡʱ�䣬Ԥ��ʱ�����߳�
		//��ֹͬһ�߳�ִ�ж��
	}

	system("pause");
}




ͬ�����ƣ����д�������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h >
int flag = 0;//Ϊ0û�ҵ�
int *addfind = NULL;
struct Mystruct{
	int *startaddress;//Ҫ���ҵ��׵�ַ
	int length;		  //�޶�����
	int *pflag;		  //Ϊ0��ʾ�ҵ�������֪ͨ�����̴߳���flag��ַ
	int num;		 //Ҫ���ҵ�����
	int bh;			//������ڱ���߳�
	int **addr;		//����ָ���ַ�������޸�һ��ָ��
};
typedef struct Mystruct	M;
void find(void *p)
{
	M *pstruct = (M *)p;
	//�ڴ����ݵı������ӿ�ʼ�ۼ�100��Ԫ��
	for (int *px = pstruct->startaddress; px < pstruct->startaddress+100; px++)
	{
		Sleep(100);
		if (*(pstruct->pflag) != 0)
		{
			printf("%d��δ�ҵ�\n", pstruct->bh);
			return;
		}
		if (*px == pstruct->num)//�ж��Ƿ��ҵ�����
		{
			printf("******��%d���߳��ҵ�******%p,%d\n", pstruct->bh,px, *px);
			*(pstruct->pflag) = 1;//Ϊ1�����ҵ�
			*(pstruct->addr) = px;
			return;
		}
	}
	printf("��%d���߳���û���ҵ���\n",pstruct->bh);
}
void main()
{
	int a[1000];
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;
	}
	M threaddata[10];//�����ṹ������,��ֹ������������ȡͬһƬ�ڴ������
	//����10���߳�
	for (int j = 0; j < 10; j++)
	{
		//��ַΪa a+100 a+200...
		int *p = a + j * 100;
		threaddata[j].startaddress = p;
		threaddata[j].length = 100;//�޶�����
		threaddata[j].bh = j;
		threaddata[j].num = 668;
		threaddata[j].pflag = &flag;//flag���ڱ�ʶ
		threaddata[j].addr = &addfind;
		_beginthread(find, 0, &threaddata[j]);
		Sleep(10);
		//Windows���̲߳�������ȫ��ʡʱ�䣬Ԥ��ʱ�����߳�
		//��ֹͬһ�߳�ִ�ж��
	}
	Sleep(10000);
	printf("\n\n%d,%p", *addfind, addfind);

	system("pause");
}