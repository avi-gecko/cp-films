#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>
#include <limits>

#ifdef _WIN32
void clear()
{
    system("cls");
}

void wait()
{
    system("pause");
}

#elif __linux__

void clear()
{
    system("clear");
}

void wait()
{
    std::cout << "Нажмите любую клавишу для продолжения..." << std::endl;
    system("read -s -N 1");
}
#endif

void show_menu(const std::string items[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        std::cout << items[i] << '\n';
    }
}

void show_file(const Films structures[], int len)
{
    clear();
    for (int i = 0; i < len; ++i)
    {
        std::cout << structures[i].id << ' '
                  << structures[i].title << ' '
                  << structures[i].studio << ' '
                  << structures[i].genre << ' '
                  << structures[i].year_publishing << ' '
                  << structures[i].inStock << ' '
                  << structures[i].year_publishing << std::endl;
    }
    wait();
}

void about()
{
    clear();
    std::cout << "Создано Алексеем Ильином ИЦТМС 2-5" << std::endl;
    wait();
}
