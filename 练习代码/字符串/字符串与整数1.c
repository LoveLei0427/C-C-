//�ַ�����12345���������12345

#include<stdio.h>
#include<stdlib.h>
#define FAUSE -1
int change1(char *str)
{
	char *istr=str;//����ָ�뱣������
	int num = 0;
	while (*str != '\0')
	{
		//�ж��ַ��Ƿ���0-9֮��
		if ((*str<'0')||(*str)>'9')
		{
			return -1;
		}
		str++;
		num++;//����ͳ���ж���λ
	}
	printf("һ����%dλ\n", num);
	int res = 0;
	for (int i = 0; i < num; i++)
	{
		res *= 10;				
		int wei = istr[i] - 48;//ȡ����Ӧ�ַ���Ӧ��ASCAIIֵ��48������εõ�ÿһλ
		res += wei;
		printf("%d", wei);
	}
	return res;//��ʱresҲΪ25678
}
/*	i	res		wei		res
    	0    	0		2		2
    	1    	20		5		25
	2    	250		6		256
	3    	2560   		7       	2567
	4	25670  		8       	25678
*/
void main()
{
	char str[10] = "25678";
	int i;;
	//ͨ������change1�ı�
	printf("\n����change2����:\n");
	change1(str);
	getchar();
}