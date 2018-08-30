/**/

#include"stdafx.h"
#include<windows.h>
#include<iostream>

typedef BOOL(*Func)(); //函数指针标准写法


int _tmain(int argc, _TCHAR* argv[])
{	 
	DWORD dwError = NOERROR;   
	BOOL bRet = FALSE;
	HINSTANCE hDll = nullptr;
	do
	{
		hDll = LoadLibraryW(L"SetWindowsHookDLL.dll");
		
		//有错误结束
		if (!hDll)
		{
			dwError = GetLastError();
			break;  //return 1
		}
		//调用dllmain中方法StartHook
		Func fun = (Func)GetProcAddress(hDll, "StartHook");
		if (!fun)//空指针的情况下
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


	//本程序HOOK需要在DLL动态链接库中实现这个函数 因为只有在动态链接库里才是全局共享
	//解决方案--添加-Win32项目-下一步改为DLL  然后在新生成的dllmanin中写一个HOOK
	if (hDll)
	{
		FreeLibrary(hDll);
	}
	std::cin.get();
	return 0;
	
}