/*
	��������������N��ѧ�������� ѧ�� M�ſεĳɼ�  �������ܳɼ� �����ܷ��ų�����  �����ѧ�Ŵ�ӡ�ɼ���
	Ҫ�㣺	�Զ����µ����˼·
*/
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
const int Course_Max = 3;
const int Student_Max = 3;

struct Student{
	string S_Name;
	string S_Id;
	int score[Course_Max];
	int total;
	int rank;
};

int main(){
	Student stu[Student_Max];
	
	//������Ϣ
	for (int i = 0; i < Student_Max; i++)
	{
		cin >> stu[i].S_Name;
		cin >> stu[i].S_Id;

		for (int j = 0; j < Course_Max; j++)
		{
			cin >> stu[i].score[j];
		}
	}

	//�����ܷ�
	for (int i = 0; i < Student_Max; i++)
	{
		int sum = 0;
		for (int j = 0; j < Course_Max; j++)
		{
			sum += stu[i].score[j];
		}
		stu[i].total = sum;
	}

	//�����ּܷ�������
	//��ÿ��Ԫ��ͳ�ƴ�������Ԫ�ظ��� Ȼ��ӱ�������
	for (int i = 0; i < Student_Max; i++)
	{
		stu[i].rank = 1;
		for (int j = 0; j < Student_Max; j++)
		{
			if (stu[j].total>stu[i].total)
			{
				stu[i].rank++;
			}
		}
	}

	//��ѧ������(ð������)
	for (int i = 0; i < Student_Max - 1; i++)
	{
		for (int j = 0; j < Student_Max - i - 1; j++)
		{
			if (stu[j].S_Id>stu[j + 1].S_Id)
			{
				swap(stu[j], stu[j + 1]);
			}
		}
	}

	//��ӡ�ɼ���
	cout << "ѧ��\t����";
	for (int j = 0; j < Course_Max; j++)
	{
		cout<<"  "<<"\t�ɼ�";
	}
	cout << "\t�ܷ�\t����" << endl;
	
	//�ɼ�������
	for (int i = 0; i < Student_Max; i++)
	{
		cout << stu[i].S_Id<<"\t"<<stu[i].S_Name;
		for (int j = 0; j < Course_Max; j++)
		{
			cout << "\t" << stu[i].score[j];
		}
		cout <<"\t"<< stu[i].total;
		cout <<"\t"<< stu[i].rank;
		cout << endl;
	}

	system("pause..");
}