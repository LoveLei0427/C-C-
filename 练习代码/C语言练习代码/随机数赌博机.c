#include<stdio.h>
#include <time.h>
int main()
{ 			//�������ʱ��ĺ��� time ��ȡʱ�䱣����ts��
	time_t ts;                      //����ʱ����������
	srand((unsigned int)time(&ts)); //�������������
	int num = rand()%100+1;		//ȡ����0-99��+1
	printf("%d\n",num);
	num > 90 ? printf("��Ӯ��!") : printf("������!");
	printf("\n");
	return 0;
}