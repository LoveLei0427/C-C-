/*
使用int main(int argc,char *argv[])时出错 未解决*/
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

void Calendar(int year, int month);//打印日历

/*int Weekday(year, month, 1);
计算某月的第一天是周几
<ctime>中有关于时间的函数 time_t mktime(struct tm*);
struct tm{
int tm_sec;(0-59)
int tm_min;(0-89)
int hour;0-23
int tm_mday;(1-31)
int month;
int tm_year; 从1990起
int tm_wday;(0-6)
int tm_yday;0-365
int tm_isdit;
};
*/

void Calendar(int year, int month)
{
	int MonthDays(int year, int month);//计算一个月有多少天
	int Weekday(int year, int  month, int day);//计算某月的第一天是周几
	cout << year << "/" << month << endl;
	cout << "==========================" << endl;
	cout << "SUN MON TUE WED THU FRI SAT" << endl;
		cout << "--------------------------" << endl;
	//打印日历表中的日期
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
		cout << setw(4) << d; //setw(int n)用来控制输出间隔n-1个空格头文件<iomanip>
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
	//int year = atoi(argv[1]);	//atoi把字符串转换成整型数的一个函数
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

