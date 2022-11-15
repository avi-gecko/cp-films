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
    std::wcout << L"Нажмите любую клавишу для продолжения..." << std::endl;
    system("read -s -N 1");
}
#endif

void show_menu(const std::wstring items[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        std::wcout << items[i] << '\n';
    }
}

void show_file(const Films structures[], int len)
{
    int i;
    int horizontal_length = 0;
    unsigned long max_length_id = 0;
    unsigned long max_length_title = 0;
    unsigned long max_length_studio = 0;
    unsigned long max_length_genre = 0;
    unsigned long max_length_year_publishing = 0;
    unsigned long max_length_in_stock = 0;
    unsigned long max_length_purchasing = 0;
    for (i = 0; i < len; ++i)
    {
        if (max_length_id < std::to_string(structures[i].id).length())
            max_length_id = std::to_string(structures[i].id).length();
        if (max_length_title < structures[i].title.length())
            max_length_title = structures[i].title.length();
        if (max_length_studio < structures[i].studio.length())
            max_length_studio = structures[i].studio.length();
        if (max_length_genre < structures[i].genre.length())
            max_length_genre = structures[i].genre.length();
        if (max_length_year_publishing < std::to_string(structures[i].year_publishing).length())
            max_length_year_publishing = std::to_string(structures[i].year_publishing).length();
        if (max_length_in_stock < std::to_string(structures[i].in_stock).length())
            max_length_in_stock = std::to_string(structures[i].in_stock).length();
        if (max_length_purchasing < std::to_string(structures[i].year_purchasing).length())
            max_length_purchasing = std::to_string(structures[i].year_purchasing).length();
    }
    horizontal_length = max_length_id + max_length_title + max_length_studio + max_length_genre + max_length_year_publishing + max_length_in_stock + max_length_purchasing;
    horizontal_length += 22;
    std::wstring horizontal_line = L"";
    for (i = 0; i < horizontal_length; ++i)
        horizontal_line += L"-";
    std::wstring vertical_line = L" | ";
    clear();
    std::wcout << L"  " << horizontal_line << std::endl;
    for (i = 0; i < len; ++i)
    {
        std::wcout << L" " << vertical_line << structures[i].id << vertical_line
                  << structures[i].title << vertical_line
                  << structures[i].studio << vertical_line
                  << structures[i].genre << vertical_line
                  << structures[i].year_publishing << vertical_line
                  << structures[i].in_stock << vertical_line
                  << structures[i].year_purchasing << vertical_line << std::endl;
    }
    wait();
}

void about()
{
    clear();
    std::wcout << L"Создано Алексеем Ильином ИЦТМС 2-5" << std::endl;
    wait();
}
