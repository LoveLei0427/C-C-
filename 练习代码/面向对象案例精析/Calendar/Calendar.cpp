/*
ʹ��int main(int argc,char *argv[])ʱ���� δ���*/
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<iomanip>
using namespace std;

//struct tm{
//	int tm_sec;
//	int tm_min; 
//	int tm_hour;
//	int tm_mday; 
//	int tm_month;
//	int tm_year; 
//	int tm_wday;
//	int tm_yday; 
//	int tm_isdit;
//};

void Calendar(int year, int month);//��ӡ����

/*int Weekday(year, month, 1);
����ĳ�µĵ�һ�����ܼ�
<ctime>���й���ʱ��ĺ��� time_t mktime(struct tm*);
struct tm{
int tm_sec;(0-59)
int tm_min;(0-89)
int hour;0-23
int tm_mday;(1-31)
int month;
int tm_year; ��1990��
int tm_wday;(0-6)
int tm_yday;0-365
int tm_isdit;
};
*/

void Calendar(int year, int month)
{
	int MonthDays(int year, int month);//����һ�����ж�����
	int Weekday(int year, int  month, int day);//����ĳ�µĵ�һ�����ܼ�
	cout << year << "/" << month << endl;
	cout << "==========================" << endl;
	cout << "SUN MON TUE WED THU FRI SAT" << endl;
		cout << "--------------------------" << endl;
	//��ӡ�������е�����
	int firstday = Weekday(year, month, 1);
	int mday = MonthDays(year, month);
	for (int i = 0; i < firstday; i++)
		cout << "    ";
	for (int d = 1; d < mday; d++)
	{
		if ((d + firstday - 1) % 7 == 0)
		{
			cout << endl;
		}
		cout << setw(4) << d; //setw(int n)��������������n-1���ո�ͷ�ļ�<iomanip>
	}
	cout << endl;
}

int Weekday(int year, int month, int day)
{	
	struct tm t = { 0, 0, 0, day, month - 1, year - 1900 };
	mktime(&t);
	return t.tm_wday;
}


int MonthDays(int year, int month)
{
	const int md[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		return 29;
	else
		return md[month];
}


int main(/*int argc, char *argv[]*/)
{
	/*if (argc != 3)
	{
		cout << "Usage:Calendar year month" << endl;
		exit(0);
	}*/
	printf("********\n");
	//int year = atoi(argv[1]);	//atoi���ַ���ת������������һ������
	//
	//int month = atoi(argv[2]);
	int year;
	int month;
	cin >> year;
	cin >> month;
	

	printf("*********\n");
	Calendar(year, month);
	system("pause...");
}

