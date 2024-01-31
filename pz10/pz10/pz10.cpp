// pz10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int main()
{
    const int PAGE_SIZE = 4096;
    LPVOID address = VirtualAlloc(NULL, PAGE_SIZE, MEM_COMMIT, PAGE_EXECUTE_READWRITE);  // Зарезервирование и заполнение памяти значением 7fh
    memset((void*)address, 0x7f, PAGE_SIZE);

    MEMORY_BASIC_INFORMATION mbi;
    SIZE_T result = VirtualQuery(address, &mbi, sizeof(mbi));  // Получение информацию об участке памяти

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
        std::cerr << "Failed to retrieve memory information." << std::endl;
        return 1;
    }

    VirtualFree(address, 0, MEM_RELEASE);  // Освобождение зарезервированной памяти

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
