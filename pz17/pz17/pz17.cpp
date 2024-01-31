// pz17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>

void PrintRegistryValue(HKEY hKey, const std::wstring& subKey, const std::wstring& valueName)
{
    HKEY hSubKey;
    if (RegOpenKeyEx(hKey, subKey.c_str(), 0, KEY_READ, &hSubKey) == ERROR_SUCCESS)
    {
        DWORD valueType;
        DWORD dataSize;
        if (RegQueryValueEx(hSubKey, valueName.c_str(), nullptr, &valueType, nullptr, &dataSize) == ERROR_SUCCESS)
        {
            if (valueType == REG_SZ)
            {
                std::wstring value(dataSize / sizeof(wchar_t), L'\0');
                if (RegQueryValueEx(hSubKey, valueName.c_str(), nullptr, nullptr, reinterpret_cast<LPBYTE>(&value), &dataSize) == ERROR_SUCCESS)
                {
                    std::wcout << valueName << L": " << value << std::endl;
                }
            }
            else if (valueType == REG_DWORD)
            {
                DWORD value;
                if (RegQueryValueEx(hSubKey, valueName.c_str(), nullptr, nullptr, reinterpret_cast<LPBYTE>(&value), &dataSize) == ERROR_SUCCESS)
                {
                    std::wcout << valueName << L": " << value << std::endl;
                }
            }
        }
        RegCloseKey(hSubKey);
    }
}

int main()
{
    // информация об операционной системе
    std::wstring osSubKey = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
    PrintRegistryValue(HKEY_LOCAL_MACHINE, osSubKey, L"ProductName");
    PrintRegistryValue(HKEY_LOCAL_MACHINE, osSubKey, L"CurrentBuild");
    PrintRegistryValue(HKEY_LOCAL_MACHINE, osSubKey, L"BuildLabEx");
    PrintRegistryValue(HKEY_LOCAL_MACHINE, osSubKey, L"SystemRoot");

    // информация о BIOS
    std::wstring biosSubKey = L"HARDWARE\\DESCRIPTION\\System\\BIOS";
    PrintRegistryValue(HKEY_LOCAL_MACHINE, biosSubKey, L"BIOSVendor");
    PrintRegistryValue(HKEY_LOCAL_MACHINE, biosSubKey, L"BIOSVersion");
    PrintRegistryValue(HKEY_LOCAL_MACHINE, biosSubKey, L"SystemManufacturer");

    // информация об автозапуске приложений
    std::wstring startupSubKey = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hStartupKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, startupSubKey.c_str(), 0, KEY_READ, &hStartupKey) == ERROR_SUCCESS)
    {
        DWORD count;
        if (RegQueryInfoKey(hStartupKey, nullptr, nullptr, nullptr, &count, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS)
        {
            for (DWORD i = 0; i < count; i++)
            {
                constexpr DWORD maxValueNameSize = 256;
                wchar_t valueName[maxValueNameSize];
                DWORD valueNameSize = maxValueNameSize;
                DWORD valueType;
                BYTE valueData[1024];
                DWORD valueDataSize = sizeof(valueData);
                if (RegEnumValue(hStartupKey, i, valueName, &valueNameSize, nullptr, &valueType, valueData, &valueDataSize) == ERROR_SUCCESS)
                {
                    std::wcout << valueName << std::endl;
                }
            }
        }
        RegCloseKey(hStartupKey);
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
