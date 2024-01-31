#include "framework.h"
#include "pz14.h"

#define strict
#define win32_lean_and_mean

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam); // Объявление прототипа функции-обработчика окна

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow)
{
    HWND hwnd;
    MSG msg;
    WNDCLASSEX wc;

    // Определение оконного класса
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc; // Установка функции-обработчика для окна
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
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

    // Создание окна
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"myclass",
        L"Моё первое окно!",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 500,
        NULL, NULL, hinstance, NULL);

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"Ошибка создания окна!", L"Ошибка!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, ncmdshow);
    UpdateWindow(hwnd);

    // Цикл обработки сообщений
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

    case WM_ACTIVATE:
        // Изменение цвета фона на синий
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)GetStockObject(DC_BRUSH));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(0, 0, 255)));
        RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
        break;

    case WM_MOVE:
        // Изменение цвета фона на красный
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)GetStockObject(DC_BRUSH));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(255, 0, 0)));
        RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
        break;

    case WM_RBUTTONDBLCLK:
        // Изменение цвета фона на зеленый
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)GetStockObject(DC_BRUSH));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(0, 255, 0)));
        RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
        break;

    default:
        return DefWindowProc(hwnd, umsg, wparam, lparam);
    }

    return 0;
}