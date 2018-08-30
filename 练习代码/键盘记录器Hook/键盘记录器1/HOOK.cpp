/**/

#include"stdafx.h"
#include<windows.h>
#include<iostream>

typedef BOOL(*Func)(); //����ָ���׼д��


int _tmain(int argc, _TCHAR* argv[])
{	 
	DWORD dwError = NOERROR;   
	BOOL bRet = FALSE;
	HINSTANCE hDll = nullptr;
	do
	{
		hDll = LoadLibraryW(L"SetWindowsHookDLL.dll");
		
		//�д������
		if (!hDll)
		{
			dwError = GetLastError();
			break;  //return 1
		}
		//����dllmain�з���StartHook
		Func fun = (Func)GetProcAddress(hDll, "StartHook");
		if (!fun)//��ָ��������
		{
			dwError = GetLastError();
			break;  //return 1
		}
		if (!fun())
			dwError = GetLastError();
			break;
		while (true)
		{
			char szInput[MAXBYTE] = { 0 };
			std::cin >> szInput;
			if (0 == strcmp(szInput, "yes"))
			{
				break;
			}
		}
		bRet = TRUE;
	} while (FALSE);
	if (FALSE == bRet)
	{
		std::cout << "ERROR--->"<<dwError<<std::endl;
	}


	//������HOOK��Ҫ��DLL��̬���ӿ���ʵ��������� ��Ϊֻ���ڶ�̬���ӿ������ȫ�ֹ���
	//�������--���-Win32��Ŀ-��һ����ΪDLL  Ȼ���������ɵ�dllmanin��дһ��HOOK
	if (hDll)
	{
		FreeLibrary(hDll);
	}
	std::cin.get();
	return 0;
	
}