// ScreenCapture.cpp : 定义应用程序的入口点。
/*
1、窗口最大化 (1)creatwindow();(2)showwindow();
2、获取整个图像 ScreenCapture();BitBle();
3、将图像放到整个窗口上
4、在窗口上画出矩形

改进地方：
鼠标移动时 画框跟着变化
未选中地方应该变灰色  选中之后变量   不能实现CTRL+v CTRL+c 
*/

#include "stdafx.h"
#include "ScreenCapture.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名


HDC g_srcMemDc;//源桌面截图
int srceenW;  //屏幕的宽和高
int srceenH;
void ScreenCapture();
void CopyBitmapToCipBoar();

RECT rect;   //矩形区域
BOOL isSelect = FALSE;//判断是否选中区域 防止和单击鼠标冲突
BOOL isDown = FALSE;//判断鼠标是否已经按下


// 此代码模块中包含的函数的前向声明: 
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

	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SCREENCAPTURE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SCREENCAPTURE));

	// 主消息循环: 
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
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	//添加鼠标样式cs_dblckls 双击保存
	wcex.style = CS_HREDRAW | CS_VREDRAW|CS_DBLCLKS;
	wcex.lpfnWndProc = WndProc;//窗口过程函数
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SCREENCAPTURE));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_SCREENCAPTURE);//设为0则无窗口菜单选项
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口  用于创建窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中
	//类名称，窗口标题，窗口弹出的样式，窗口大小和位置（4个参数）...
	hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, SW_MAXIMIZE);//此处让窗口最大化
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//   系统调用  当有消息时调用 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	//创建透明的画刷
	LOGBRUSH brush;
	brush.lbStyle = BS_NULL;
	HBRUSH hBrush = CreateBrushIndirect(&brush);
	//定义笔的大小为2个像素
	LOGPEN pen;
	POINT pt;
	pt.x = 2;
	pt.y = 2;
	//定义笔的颜色绿色  实线
	pen.lopnColor = 0x0000FFFF;
	pen.lopnStyle = PS_SOLID;
	pen.lopnWidth = pt;
	//创建笔
	HPEN hPen = CreatePenIndirect(&pen);

	switch (message)  //消息ID 用于表示鼠标点击等
	{

		/*case WM_LBUTTONDOWN:
		MessageBox(hWnd,L"左键按下",L"Lift",MB_OK);
		break;*/
	case WM_LBUTTONDOWN:
	{
		 if (!isSelect)//如果没有选中的情况下 不会复制 
		 {
			POINT pt;
			GetCursorPos(&pt);//得到当前光标的位置
			rect.left = pt.x;
			rect.top = pt.y;
			rect.right = pt.x;
			rect.bottom = pt.y;
			InvalidateRgn(hWnd, 0, true);//刷新屏幕

			isDown = TRUE;
		 }
	
	}
	break;

	case WM_LBUTTONUP:
	{
		if (isDown == TRUE&&!isSelect)
		{
			POINT pt;
			GetCursorPos(&pt);//得到当前光标的位置
		    rect.right = pt.x;
			rect.bottom = pt.y;
			InvalidateRgn(hWnd, 0, true);
			isDown = FALSE;
			isSelect = TRUE;//鼠标弹起时表示区域选中
		}
	}
	break;

	case WM_MOUSEMOVE:

		break;
	case WM_LBUTTONDBLCLK://鼠标双击复制选中区域
		if (isSelect)
		{
			CopyBitmapToCipBoar();//选中区域到粘贴板
			isSelect = FALSE;
		}
		
		break;
	case WM_CREATE:
		ScreenCapture();
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
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
		hdc = BeginPaint(hWnd, &ps);//hdc代表当前窗口
		// TODO:  在此添加任意绘图代码...
		
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);

		//g_srcMemDc;
		//将整个桌面放到了全屏的画布上
		BitBlt(hdc, 0, 0, srceenW, srceenH, g_srcMemDc, 0, 0, SRCCOPY);

		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);//画出矩形

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

// “关于”框的消息处理程序。
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


//获取整个桌面的图像
void ScreenCapture()
{
	//创建画笔Dc 设备上下文  与窗口有关
	HDC disDc = ::CreateDC(L"DISPLAY", 0, 0, 0);//创建一个图像 DISPLAY桌面的意思
	//得到窗口大小分辨率
	srceenW = GetDeviceCaps(disDc, HORZRES);//获取整个桌面水平大小
	srceenH = GetDeviceCaps(disDc, VERTRES);//垂直大小

	//获取截图
	g_srcMemDc = CreateCompatibleDC(disDc);//创建一个兼容DC 与桌面相关的
	//模拟一张画布出来
	HBITMAP hbitMap = CreateCompatibleBitmap(disDc, srceenW, srceenH);//与桌面大小相同
	//将画布选入到Dc
	SelectObject(g_srcMemDc, hbitMap);
	//将屏幕画到画布上
	BitBlt(g_srcMemDc, 0, 0, srceenW, srceenH, disDc, 0, 0, SRCCOPY);

}
void CopyBitmapToCipBoar()//复制鼠标选中去到粘贴板
{
	//得到矩形框的宽和高
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	HDC hSrcDc = ::CreateDC(L"DISPLAY", 0, 0, 0);
	HDC memDc = CreateCompatibleDC(hSrcDc);
	HBITMAP bmp = CreateCompatibleBitmap(hSrcDc,width,height);//模拟画布 不是全屏
	HBITMAP oldmap = (HBITMAP)SelectObject(memDc,bmp);//将画布选中到笔中
	
	//SelectObject(memDc, bmp);
	
	//将桌面选中部分拷贝到画布memDc上面
	BitBlt(memDc, 0, 0, width, height, hSrcDc,rect.left, rect.top, SRCCOPY);
	HBITMAP newmap = (HBITMAP)SelectObject(memDc,oldmap);
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, newmap);
		CloseClipboard();
	}
}
