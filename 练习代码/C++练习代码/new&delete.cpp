#include<iostream>
using namespace std;
int main()
{
	//��̬�������ʹ洢�ռ䲢��ֵ
	int *p1;
	p1 = new int;
	if (!p1)
	{
		cout << "Allocation Failure" << endl;
		return 1;
	}
	*p1 = 100;
	cout << *p1 << endl;  //100
	delete p1;			//�����ҽ����ͷ�һ��

	//Ϊһά�������ռ�
	char *p2 = new char[5];
	p2[0] = 'L';
	p2[1] = 'o';
	p2[2] = 'v';
	p2[3] = 'e';
	p2[4] = '\0';		//Ҫ��'\0'��β�����Խ������
	cout << p2 << endl;  //Love
	delete[] p2;

	//��ά��������ڴ�
	int **p3;
	p3 = new int*[3];		//���ٴ�СΪ3��ָ��int�͵�ָ��
	//p3�൱�������׵�ַ

	for (int i = 0; i < 3; i++)
	{
		p3[i] = new int[4];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			p3[i][j] = i + j;
			cout << ' ' << p3[i][j];   // 0 1 2 3
		}                              // 1 2 3 4
		cout << endl;                  // 2 3 4 5
	}
	for (int i = 0; i < 3; i++)
	{
		delete[]p3[i];
	}
	delete[]p3;

	//�����ڴ��ͬʱ��ʼ���������ö�̬���������洢��
	int *p4 = new int(99);
	cout << *p4 << endl;                       //99
	delete p4;

	system("pause");
}