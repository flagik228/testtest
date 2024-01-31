#include "framework.h"
#include "pz14.h"

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#include "../MathLibrary22/MathLib.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG msg;
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"myclass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, L"Регистрация окна не удалась!", L"Ошибка!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"myclass",
        L"Моё первое окно!",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 500,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"Ошибка создания окна!", L"Ошибка!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
    switch (umsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:
        CreateWindowW(L"BUTTON", L"Вычислить", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            20, 20, 100, 30, hwnd, (HMENU)1, NULL, NULL);

        CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            20, 70, 100, 25, hwnd, (HMENU)2, NULL, NULL);

        CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
            20, 110, 100, 25, hwnd, (HMENU)3, NULL, NULL);

        CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_READONLY,
            20, 150, 100, 25, hwnd, (HMENU)4, NULL, NULL);
        break;

    case WM_COMMAND:
        if (HIWORD(wparam) == BN_CLICKED)
        {
            // Обработка нажатия кнопки "Вычислить"
            if (LOWORD(wparam) == 1)
            {
                HWND hEditA = GetDlgItem(hwnd, 2);
                HWND hEditB = GetDlgItem(hwnd, 3);
                HWND hResult = GetDlgItem(hwnd, 4);

                int bufferLength = GetWindowTextLength(hEditA) + 1;
                wchar_t* bufferA = new wchar_t[bufferLength];
                GetWindowText(hEditA, bufferA, bufferLength);

                bufferLength = GetWindowTextLength(hEditB) + 1;
                wchar_t* bufferB = new wchar_t[bufferLength];
                GetWindowText(hEditB, bufferB, bufferLength);

                double a = _wtof(bufferA);
                double b = _wtof(bufferB);

                // Вызываем необходимую функцию из библиотеки mathlibrary
                double result = MathLibrary::Arithmetic::Add(a, b);

                std::wstring resultStr = std::to_wstring(result);
                LPCWSTR resultCStr = resultStr.c_str();

                SetWindowText(hResult, resultCStr);

                delete[] bufferA;
                delete[] bufferB;
            }
        }
        break;

    default:
        return DefWindowProc(hwnd, umsg, wparam, lparam);
    }

    return 0;
}