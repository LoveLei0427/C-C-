//������̺Ͷ���ķ��� �鿴���̲����в���
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

////1��������̷���
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

//2���������ķ���������� ��ķ�װ����ͻ��Ȩ��
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
		memset(this->cmd, 0, 100);//����ַ���
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
	char cmduser[100];//�洢�û���
	char cmd[100];//ָ��洢
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
	////ͨ��pid���н��̹ر�
	//int id;
	//scanf("%d", &id);
	//CloseById(id);
	//
	system("pause");
}