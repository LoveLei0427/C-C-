/*
1.�Զ����µ����˼��
2.ʹ�ú���
*/
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int const Student_Max = 3;
int const Course_Max = 3;
static int i = 0;
static int j = 0;
struct  Student
{
	string id;
	string name;
	int score[Course_Max];
	int total;
	int rank;
};

void InputStudentInfo();//����ѧ����Ϣ
void ComputeTotalScore();//�����ܳɼ�
void CountRankOfTotal();//�����ּܷ�������
void PrintScoreReport();//��ӡ�ɼ�
void SortById();//��ѧ������

typedef Student Stu;
Stu stu[Student_Max];

int main()
{
	
	InputStudentInfo();
	ComputeTotalScore();
	CountRankOfTotal();
	PrintScoreReport();

	system("pause..");
}

void InputStudentInfo()
{
	for (i = 0; i < Student_Max; i++)
	{
		cout << "ѧ��" << (i + 1) << "(ѧ�ţ�������" << Course_Max << "�ſγɼ���:";
		cin >> stu[i].id >> stu[i].name;
		for (j = 0; j < Course_Max; j++)
		{
			cin >> stu[i].score[j];
		}
	}

}


void ComputeTotalScore(){
	for (i = 0; i < Student_Max; i++)
	{
		int sum = 0;
		for (j = 0; j < Course_Max; j++)
		{
			sum += stu[i].score[j];
		}
		stu[i].total = sum;
	}
}

void CountRankOfTotal()
{
	for (i = 0; i < Student_Max; i++)
	{
		stu[i].rank = 1;
		for (j = 0; j < Student_Max; j++)
		{
			if (stu[i].total < stu[j].total)
			{
				stu[i].rank++;
			}
		}
	}
}

void PrintScoreReport(){
	SortById();
	cout << "ѧ��\t����";
	for (j = 0; j < Course_Max; j++)
	{
		cout<<"  "<<"\t�ɼ�";
	}
	cout << "\t�ܷ�\t����" << endl;		
	for (i = 0; i < Student_Max; i++)
	{
		cout << stu[i].id<<"\t"<<stu[i].name;
		for (j = 0; j < Course_Max; j++)
		{
			cout << "\t" << stu[i].score[j];
		}
		cout <<"\t"<< stu[i].total;
		cout <<"\t"<< stu[i].rank;
		cout << endl;
	}
}


void SortById(){
	for (i = 0; i < Student_Max - 1; i++)
	{
		for (j = 0; j < Student_Max - i - 1; j++)
		{
			if (stu[j].id>stu[j + 1].id)
			{
				swap(stu[j], stu[j + 1]);
			}
		}
	}

}



