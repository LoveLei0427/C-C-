//************�������ָ����ַ�����ڼ�����ֵΪ123�ı�����ַ���ı�----ģ��ʵ��
//ʹ�ý��̡��̡߳�����ģ�顢���̴��ڡ������ڴ���Ϣ�鿴����XueTr
//��������ͬ1
#include<stdio.h>
#include<stdlib.h>
_declspec(dllexport) void go()
{
	void *startp = (void *)0x1db80000;
	void *endp = (void *)0x1db81000;//����ɨ��ĵ�ַ����
	for (char *p = startp; p != endp; p++)//ÿ���ƶ�һ���ֽڱ�֤�����ĸ��ֽڷֿ�ʱ���ݶ�ʧ�����
	{
		int *px = (int *)p;//����ת��Ϊint��ǰ��ȡ�ĸ��ֽڣ�����ֵ�ǲ���Ϊ123
		if (*px == 123)
		{
			*px = 555;//��������ֵ
		}
	}
	getchar();
}



//�����ڴ�ʵ�������Զ���ֵ
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
_declspec(dllexport) void go()
{
	void *startp = (void *)0x1db80000;
	void *endp = (void *)0x1db81000;
	int *valuep = NULL;//��ֹҰָ��;
	for (char *p = startp; p!= endp; p++)
	{
		int *px = (int *)p;
		if (*px == 555)
		{
			*px = 100;
			valuep = px;
			break;//�ҵ���Ҫ�Ըĵ�ֵ������
		}
	}
	while (1)
	{
		if(*valuep <= 100)
		{
			*valuep = 200;
		}
		Sleep(5000);//5S���һ�ε���100�ͳ�ֵΪ200
	}
		
	getchar();
}
