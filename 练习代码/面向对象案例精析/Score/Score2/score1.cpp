/*
1.自定向下的设计思想
2.使用函数
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

void InputStudentInfo();//输入学生信息
void ComputeTotalScore();//计算总成绩
void CountRankOfTotal();//按照总分计算排名
void PrintScoreReport();//打印成绩
void SortById();//按学号排序

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
		cout << "学生" << (i + 1) << "(学号，姓名，" << Course_Max << "门课成绩）:";
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
	cout << "学号\t姓名";
	for (j = 0; j < Course_Max; j++)
	{
		cout<<"  "<<"\t成绩";
	}
	cout << "\t总分\t名次" << endl;		
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



