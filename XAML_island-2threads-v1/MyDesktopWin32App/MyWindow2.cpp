#include "MyWindow2.h"
#include "MyWindow1.h"

#include "framework.h"

// Global Variables:
HINSTANCE g_hInst2;                                // current instance
WCHAR g_szTitle2[MAX_LOADSTRING] = L"second_Window_title";                  // The title bar text
WCHAR g_szWindowClass2[MAX_LOADSTRING] = L"second_Window_class";            // the main window class name





DWORD  Window2ThreadFunc(LPVOID lpParam)
{
    Log("starting the thread");

    // Initialize global strings
    //LoadStringW(g_hInstance, IDS_APP_TITLE, g_szTitle2, MAX_LOADSTRING);
    //LoadStringW(g_hInstance, IDC_MYDESKTOPWIN32APP, g_szWindowClass2, MAX_LOADSTRING);

    Log("registering the class");
    MyRegisterClass2(g_hInstance);

    Log("init instance");
    // Perform application initialization:
    if (!InitInstance2(g_hInstance, SW_SHOW))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(g_hInstance, MAKEINTRESOURCE(IDC_MYDESKTOPWIN32APP));

    MSG msg;

    Log("starting message loop for the thread");
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }


    Log("closing the thread");
    return 0;
}
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass2(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc2;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYDESKTOPWIN32APP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MYDESKTOPWIN32APP);
    wcex.lpszClassName = g_szWindowClass2;
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
BOOL InitInstance2(HINSTANCE hInstance, int nCmdShow)
{
    g_hInst2 = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(g_szWindowClass2, g_szTitle2, WS_OVERLAPPEDWINDOW,
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
LRESULT CALLBACK WndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            Log("received IDM_ABOUT message");
            DialogBox(g_hInst2, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About2);
            break;
        case IDM_EXIT:
            Log("received IDM_EXIT message");
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        Log("received WM_DESTROY message");
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
