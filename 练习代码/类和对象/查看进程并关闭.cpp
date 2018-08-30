//面向过程和对象的方法 查看进程并进行操作
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

////1、面向过程方法
//void OpenTask(char *path,int mode)
//{
//	ShellExecuteA(0, "open", path, 0, 0, mode);
//}
//void AllTask()
//{
//	system("tasklist");
//}
//void CloseById(const int id) 
//{
//	char cmdstr[100] = { 0 };
//	sprintf(cmdstr, "taskkill /pid %d", id);
//	system(cmdstr);
//}
//void CloseByName(const char *name)
//{
//	char cmdstr[100] = { 0 };
//	sprintf(cmdstr, "taskkill /f /im %s", name);//im=image name
//	system(cmdstr);
//}

//2、面向对象的方法管理进程 类的封装可以突出权限
class User{
	
public:
	void OpenTask(char *path, int mode)
	{
		ShellExecuteA(0, "open", path, 0, 0, mode);
	}
	void AllTask()
	{
		system("tasklist");
	}
	void CloseById(const int id)
	{
		memset(this->cmd, 0, 100); 
		sprintf(this->cmd, "taskkill /pid %d", id);
		system(this->cmd);
	}
	void CloseByName(const char *name)
	{
		memset(this->cmd, 0, 100);//清空字符串
		sprintf(this->cmd, "taskkill /f /im %s", name);//im=image name
		system(this->cmd);
	}
	void SetUser(const char* name)
	{
		strcpy(cmduser, name);
	}
	char *GetUser()
	{
		return this->cmduser; 
	}

private:
	char cmduser[100];//存储用户名
	char cmd[100];//指令存储
};

int main(void)
{
	User test;
	test.SetUser("Host");
	cout << test.GetUser() << endl;
	test.OpenTask("calc",1);
	test.AllTask();
	Sleep(5000);
	test.CloseByName("calc.exe");
	//OpenTask("notepad", 1);
	//AllTask();	
	//Sleep(3000);
	//CloseByName("notepad");	
	////通过pid进行进程关闭
	//int id;
	//scanf("%d", &id);
	//CloseById(id);
	//
	system("pause");
}