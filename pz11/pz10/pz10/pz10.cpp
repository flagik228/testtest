// pz10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main()
{
    // пз10

    const int page_size = 4096;
    LPVOID address = VirtualAlloc(NULL, page_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE); // зарезервирование и заполнение памяти значением 7fh
    if (address == NULL)
    {
        std::cerr << "Не удалось выделить память." << std::endl;
        return 1;
    }

    memset(address, 0x7f, page_size);

    MEMORY_BASIC_INFORMATION mbi;
    size_t result = VirtualQuery(address, &mbi, sizeof(mbi)); // получение информации об участке памяти

    if (result != 0)
    {
        std::cout << "Base address: " << mbi.BaseAddress << std::endl;
        std::cout << "Allocation base: " << mbi.AllocationBase << std::endl;
        std::cout << "Allocation protect: " << mbi.AllocationProtect << std::endl;
        std::cout << "Region size: " << mbi.RegionSize << std::endl;
        std::cout << "State: " << mbi.State << std::endl;
    }
    else
    {
        std::cerr << "Не удалось получить информацию из памяти." << std::endl;
        return 1;
    }

    VirtualFree(address, 0, MEM_RELEASE); // освобождение зарезервированной памяти

    // пз11 1)

    LPVOID address2 = VirtualAlloc(NULL, page_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE); // зарезервирование и заполнение памяти значением 7fh
    if (address2 == NULL)
    {
        std::cerr << "Не удалось выделить память." << std::endl;
        return 1;
    }

    DWORD oldProtect;
    BOOL result2 = VirtualProtect(address2, page_size, PAGE_READWRITE, &oldProtect);
    if (result2 != 0)
    {
        std::cout << "VirtualProtect - успех" << std::endl;
    }
    else
    {
        DWORD lastError = GetLastError();
        LPTSTR lpMsgBuf;
        DWORD bufSize = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, lastError, 0, (LPTSTR)&lpMsgBuf, 0, NULL);
        if (bufSize != 0)
        {
            std::cerr << "VirtualProtect - не удалось с ошибкой: " << lpMsgBuf << std::endl;
            LocalFree(lpMsgBuf);
        }
        else
        {
            std::cerr << "VirtualProtect - не удалось с кодом ошибки: " << lastError << std::endl;
        }
        return 1;
    }

    // пз11 2)

    LPVOID address3 = VirtualAlloc(NULL, page_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE); // зарезервирование и заполнение памяти значением 7fh
    if (address3 == NULL)
    {
        std::cerr << "Не удалось выделить память." << std::endl;
        return 1;
    }

    MEMORY_BASIC_INFORMATION mbi2;
    size_t result3 = VirtualQuery(address3, &mbi2, sizeof(mbi2)); // получение информации об участке памяти

    if (result3 != 0)
    {
        std::cout << "Base address: " << mbi2.BaseAddress << std::endl;
        std::cout << "Allocation base: " << mbi2.AllocationBase << std::endl;
        std::cout << "Allocation protect: " << mbi2.AllocationProtect << std::endl;
        std::cout << "Region size: " << mbi2.RegionSize << std::endl;
        std::cout << "State: " << mbi2.State << std::endl;
    }
    else
    {
        DWORD lastError = GetLastError();
        LPTSTR lpMsgBuf;
        DWORD bufSize = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, lastError, 0, (LPTSTR)&lpMsgBuf, 0, NULL);
        if (bufSize != 0)
        {
            std::cerr << "Не удалось получить информацию из памяти: " << lpMsgBuf << std::endl;
            LocalFree(lpMsgBuf);
        }
        else
        {
            std::cerr << "Не удалось получить информацию о памяти с кодом ошибки: " << lastError << std::endl;
        }
        return 1;
    }

    VirtualFree(address3, 0, MEM_RELEASE); // освобождение зарезервированной памяти

    return 0;
}

