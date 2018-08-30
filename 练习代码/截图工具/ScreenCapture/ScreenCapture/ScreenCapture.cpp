// ScreenCapture.cpp : ����Ӧ�ó������ڵ㡣
/*
1��������� (1)creatwindow();(2)showwindow();
2����ȡ����ͼ�� ScreenCapture();BitBle();
3����ͼ��ŵ�����������
4���ڴ����ϻ�������

�Ľ��ط���
����ƶ�ʱ ������ű仯
δѡ�еط�Ӧ�ñ��ɫ  ѡ��֮�����   ����ʵ��CTRL+v CTRL+c 
*/

#include "stdafx.h"
#include "ScreenCapture.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������


HDC g_srcMemDc;//Դ�����ͼ
int srceenW;  //��Ļ�Ŀ�͸�
int srceenH;
void ScreenCapture();
void CopyBitmapToCipBoar();

RECT rect;   //��������
BOOL isSelect = FALSE;//�ж��Ƿ�ѡ������ ��ֹ�͵�������ͻ
BOOL isDown = FALSE;//�ж�����Ƿ��Ѿ�����


// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SCREENCAPTURE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SCREENCAPTURE));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	//��������ʽcs_dblckls ˫������
	wcex.style = CS_HREDRAW | CS_VREDRAW|CS_DBLCLKS;
	wcex.lpfnWndProc = WndProc;//���ڹ��̺���
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SCREENCAPTURE));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_SCREENCAPTURE);//��Ϊ0���޴��ڲ˵�ѡ��
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������  ���ڴ�������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����
	//�����ƣ����ڱ��⣬���ڵ�������ʽ�����ڴ�С��λ�ã�4��������...
	hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, SW_MAXIMIZE);//�˴��ô������
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//   ϵͳ����  ������Ϣʱ���� 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	//����͸���Ļ�ˢ
	LOGBRUSH brush;
	brush.lbStyle = BS_NULL;
	HBRUSH hBrush = CreateBrushIndirect(&brush);
	//����ʵĴ�СΪ2������
	LOGPEN pen;
	POINT pt;
	pt.x = 2;
	pt.y = 2;
	//����ʵ���ɫ��ɫ  ʵ��
	pen.lopnColor = 0x0000FFFF;
	pen.lopnStyle = PS_SOLID;
	pen.lopnWidth = pt;
	//������
	HPEN hPen = CreatePenIndirect(&pen);

	switch (message)  //��ϢID ���ڱ�ʾ�������
	{

		/*case WM_LBUTTONDOWN:
		MessageBox(hWnd,L"�������",L"Lift",MB_OK);
		break;*/
	case WM_LBUTTONDOWN:
	{
		 if (!isSelect)//���û��ѡ�е������ ���Ḵ�� 
		 {
			POINT pt;
			GetCursorPos(&pt);//�õ���ǰ����λ��
			rect.left = pt.x;
			rect.top = pt.y;
			rect.right = pt.x;
			rect.bottom = pt.y;
			InvalidateRgn(hWnd, 0, true);//ˢ����Ļ

			isDown = TRUE;
		 }
	
	}
	break;

	case WM_LBUTTONUP:
	{
		if (isDown == TRUE&&!isSelect)
		{
			POINT pt;
			GetCursorPos(&pt);//�õ���ǰ����λ��
		    rect.right = pt.x;
			rect.bottom = pt.y;
			InvalidateRgn(hWnd, 0, true);
			isDown = FALSE;
			isSelect = TRUE;//��굯��ʱ��ʾ����ѡ��
		}
	}
	break;

	case WM_MOUSEMOVE:

		break;
	case WM_LBUTTONDBLCLK://���˫������ѡ������
		if (isSelect)
		{
			CopyBitmapToCipBoar();//ѡ������ճ����
			isSelect = FALSE;
		}
		
		break;
	case WM_CREATE:
		ScreenCapture();
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);//hdc����ǰ����
		// TODO:  �ڴ���������ͼ����...
		
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);

		//g_srcMemDc;
		//����������ŵ���ȫ���Ļ�����
		BitBlt(hdc, 0, 0, srceenW, srceenH, g_srcMemDc, 0, 0, SRCCOPY);

		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);//��������

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


//��ȡ���������ͼ��
void ScreenCapture()
{
	//��������Dc �豸������  �봰���й�
	HDC disDc = ::CreateDC(L"DISPLAY", 0, 0, 0);//����һ��ͼ�� DISPLAY�������˼
	//�õ����ڴ�С�ֱ���
	srceenW = GetDeviceCaps(disDc, HORZRES);//��ȡ��������ˮƽ��С
	srceenH = GetDeviceCaps(disDc, VERTRES);//��ֱ��С

	//��ȡ��ͼ
	g_srcMemDc = CreateCompatibleDC(disDc);//����һ������DC ��������ص�
	//ģ��һ�Ż�������
	HBITMAP hbitMap = CreateCompatibleBitmap(disDc, srceenW, srceenH);//�������С��ͬ
	//������ѡ�뵽Dc
	SelectObject(g_srcMemDc, hbitMap);
	//����Ļ����������
	BitBlt(g_srcMemDc, 0, 0, srceenW, srceenH, disDc, 0, 0, SRCCOPY);

}
void CopyBitmapToCipBoar()//�������ѡ��ȥ��ճ����
{
	//�õ����ο�Ŀ�͸�
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	HDC hSrcDc = ::CreateDC(L"DISPLAY", 0, 0, 0);
	HDC memDc = CreateCompatibleDC(hSrcDc);
	HBITMAP bmp = CreateCompatibleBitmap(hSrcDc,width,height);//ģ�⻭�� ����ȫ��
	HBITMAP oldmap = (HBITMAP)SelectObject(memDc,bmp);//������ѡ�е�����
	
	//SelectObject(memDc, bmp);
	
	//������ѡ�в��ֿ���������memDc����
	BitBlt(memDc, 0, 0, width, height, hSrcDc,rect.left, rect.top, SRCCOPY);
	HBITMAP newmap = (HBITMAP)SelectObject(memDc,oldmap);
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, newmap);
		CloseClipboard();
	}
}
