���ֲ��ң�(Ҫ��ԭ��������)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int search(int a[],int n,int num)
{
	int head = 0;
	int tail = n - 1;
	int mid = (head + tail) / 2;
	while (head <= tail)
	{
		printf("\n��ʼ����%d,%d,%d", head, mid, tail);
		if (a[mid] == num)
		{
			return mid;
		}
		else if (a[mid] > num)
		{
			tail = mid - 1;
			mid = (head + tail) / 2;
		}
		else
		{
			head = mid + 1;
			mid = (head + tail) / 2;
		}	
	}
	return -1;//ѭ��ִ������δ�ҵ�����-1
}
int main()
{
	int a[64],i;
	time_t tms;
	srand((unsigned int)time(&tms));
	for (i = 0; i<64; i++)
	{
		a[i] = rand() % 100;
		printf("\n%d", a[i]);
	}
	printf("\n");
	sort(a, 64);
	printf("�����:");
	for (i = 0; i < 64; i++)
	{
		printf("\n%d", a[i]);
	}
	int num;
	scanf("%d", &num);
	int x = search(a, 64, num);
	printf("\n%d", x);
	if (x == -1)
	{
		printf("û�ҵ�");
	}
	else
	{
		printf("�ҵ�%d", a[x]);
	}	
	system("pause");
}
search������Ҳ���Ը�Ϊforѭ��
int searchfor(int a[], int n, int num)
{
	for (int head = 0, tail = n - 1, mid = (head + tail) / 2; head <= tail; mid = (head + tail) / 2)
	{
		if (a[mid] == num)
		{
			return mid;
		}
		else if (a[mid] > num)
		{
			tail = mid - 1;
		}
		else
		{
			head = mid + 1;
		}
	}
}


��ͨʵ�֣�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int search1(int a[], int n,int num)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == num)
			return i;
	}
	return -1;
}
int main()
{
	int a[64],i;
	time_t tms;

	srand((unsigned int)time(&tms));
	for (i = 0; i<64; i++)
	{
		a[i] = rand() % 100;
		printf("\n%d", a[i]);
	}
	printf("\n");
	
	int num;
	scanf("%d", &num);
	int x = search1(a, 64, num);
	printf("\n%d", x);
	if (x == -1)
	{
		printf("û�ҵ�");
	}
	else
	{
		printf("�ҵ�%d", a[x]);
	}	
	system("pause");
}