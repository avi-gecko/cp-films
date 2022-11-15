#include "rwFunc.hpp"
#include "menu.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

Films *make_struct(const std::string file, int size)
{
    std::wifstream file_d;
    file_d.open(file, std::ios_base::in);
    if (!file_d.is_open())
    {
        clear();
        std::wcerr << L"Ошибка записи" << std::endl;
        wait();
        return nullptr;
    }
    #ifdef _WIN32
    file_d.imbue(std::locale("cp1251"));
    #elif __linux__
    file_d.imbue(std::locale("ru_RU.utf8"));
    #endif
    Films *structures = new Films[size];
    std::wstring temp;
    for (int i = 0; i < size; ++i)
    {
        std::getline(file_d, temp, L'\n');
        structures[i].id = std::stoi(temp.substr(0, temp.find(L";")));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].title = temp.substr(0, temp.find(L";"));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].studio = temp.substr(0, temp.find(L";"));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].genre = temp.substr(0, temp.find(L";"));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].year_publishing = std::stoi(temp.substr(0, temp.find(L";")));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].in_stock = std::stoi(temp.substr(0, temp.find(L";")));
        temp.erase(0, temp.find(L";") + 1);
        structures[i].year_purchasing = std::stoi(temp.substr(0, temp.find(L";")));
    }
    file_d.close();
    return structures;
}

void export_struct(const Films structures[], int len)
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
    horizontal_length += 8;
    std::wstring horizontal_line = L"";
    for (i = 0; i < horizontal_length; ++i)
        horizontal_line += L"-";
    std::wstring vertical_line = L"|";
    clear();
    std::wofstream file;
    file.open("out.txt", std::ios_base::out);
    if (!file.is_open())
    {
        clear();
        std::wcerr << L"Ошибка записи" << std::endl;
        wait();
        return;
    }
    #ifdef _WIN32
    file.imbue(std::locale("cp1251"));
    #elif __linux__
    file.imbue(std::locale("ru_RU.utf8"));
    #endif
    file << horizontal_line << std::endl;
    for (i = 0; i < len; ++i)
    {
              file << std::setw(0) << vertical_line << std::setw(max_length_id) << std::to_wstring(structures[i].id) << std::setw(0) << vertical_line
                   << std::setw(max_length_title) << structures[i].title << std::setw(0) << vertical_line
                   << std::setw(max_length_studio) << structures[i].studio << std::setw(0) << vertical_line
                   << std::setw(max_length_genre) << structures[i].genre << std::setw(0) << vertical_line
                   << std::setw(max_length_year_publishing) << std::to_wstring(structures[i].year_publishing) << std::setw(0) << vertical_line
                   << std::setw(max_length_in_stock) << std::to_wstring(structures[i].in_stock) << std::setw(0) << vertical_line
                   << std::setw(max_length_purchasing) << std::to_wstring(structures[i].year_purchasing) << std::setw(0) << vertical_line << std::endl;
    }
    file << horizontal_line << std::endl;
    clear();
    std::wcout << L"Файл успешно записан." << std::endl;
    wait();
}
