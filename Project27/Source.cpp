// 02.11.22.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "09.11.2022.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY021122, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY021122));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY021122));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_MY021122);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR buf11[100] = TEXT("Никита");
    TCHAR buf12[100] = TEXT("Мохсени");
    TCHAR buf13[100] = TEXT("10.02.2004");
    TCHAR buf21[100] = TEXT("Дмитрий");
    TCHAR buf22[100] = TEXT("Шарпило");
    TCHAR buf23[100] = TEXT("22.06.2004");
    switch (message)
    {
        /*case WM_MOUSEMOVE:
            wsprintf(buf, TEXT("X = %d  Y = %d"), LOWORD(lParam), HIWORD(lParam));
            SetWindowText(hWnd, buf);
            break;*/
    case WM_LBUTTONDOWN:
    {
        int task = MessageBox(hWnd, TEXT("Ok - резюме\nCancel - Отгадывание чисел"), TEXT("Multi-task"), MB_OKCANCEL | MB_ICONASTERISK);
        if (task == IDOK)
        {
            int rez = MessageBox(hWnd, TEXT("Yes - 1 резюме\nNo - 2 резюме\nCancel - Сред. ариф. символов"), TEXT("Резюмэ"), MB_YESNOCANCEL | MB_ICONASTERISK);
            if (rez == IDYES)
            {
                MessageBox(hWnd, buf11, TEXT("Имя"), MB_OK);
                MessageBox(hWnd, buf12, TEXT("Фамилия"), MB_OK);
                MessageBox(hWnd, buf13, TEXT("Дата рождения"), MB_OK);
            }
            else if (rez == IDCANCEL)
            {
                int rez = _tcsclen(buf11) + _tcslen(buf21) + _tcsclen(buf12) + _tcslen(buf22) + _tcsclen(buf13) + _tcslen(buf23);
                rez /= 2;
                TCHAR buf[100];
                wsprintf(buf, TEXT("Кол-во символов = %d"), rez);
                MessageBox(hWnd, buf, TEXT("WINDOW"), MB_OK);
            }
            else if (rez == IDNO)
            {
                MessageBox(hWnd, buf21, TEXT("Имя"), MB_OK);
                MessageBox(hWnd, buf22, TEXT("Фамилия"), MB_OK);
                MessageBox(hWnd, buf23, TEXT("Дата рождения"), MB_OK);
            }
            break;
        }
        else if (task == IDCANCEL)
        {
            int reply = 1;
            int temp = rand() % (1 - 100) + 1;
            while (true)
            {
                TCHAR buf[50];
                wsprintf(buf, TEXT("Ваше число: %d?"), temp);
                int rez = MessageBox(hWnd, buf, TEXT("Угадывание"), MB_YESNO | MB_ICONQUESTION);
                if (rez == IDYES)
                {
                    wsprintf(buf, TEXT("Кол-во попыток: %d"), reply);
                    MessageBox(hWnd, buf, TEXT("Угадывание"), MB_OK);
                    break;
                }
                else if (rez == IDNO)
                {
                    temp = rand() % (1 - 100) + 1;
                    reply++;
                }
            }
            break;
        }
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}