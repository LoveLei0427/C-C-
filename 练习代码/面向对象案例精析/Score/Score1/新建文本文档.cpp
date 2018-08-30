/*
	问题描述：输入N和学生的姓名 学号 M门课的成绩  并计算总成绩 按照总分排除名次  最后按照学号打印成绩单
	要点：	自顶向下的设计思路
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
	
	//输入信息
	for (int i = 0; i < Student_Max; i++)
	{
		cin >> stu[i].S_Name;
		cin >> stu[i].S_Id;

		for (int j = 0; j < Course_Max; j++)
		{
			cin >> stu[i].score[j];
		}
	}

	//计算总分
	for (int i = 0; i < Student_Max; i++)
	{
		int sum = 0;
		for (int j = 0; j < Course_Max; j++)
		{
			sum += stu[i].score[j];
		}
		stu[i].total = sum;
	}

	//按照总分计算排名
	//对每个元素统计大于它的元素个数 然后加便是名次
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

	//按学号排序(冒泡排序)
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

	//打印成绩单
	cout << "学号\t姓名";
	for (int j = 0; j < Course_Max; j++)
	{
		cout<<"  "<<"\t成绩";
	}
	cout << "\t总分\t名次" << endl;
	
	//成绩单内容
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