#include "rwFunc.hpp"
#include <iostream>
#include <fstream>

Films *make_struct(const std::string file, int size)
{
    std::wifstream file_d;
    file_d.open(file, std::ios_base::in);
    if (!file_d.is_open())
        return nullptr;
    file_d.imbue(std::locale("ru_RU.utf8"));
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

void export_struct(Films structures[], int len)
{
    for (int i = 0; i < len; ++i)
        std::wcout << structures[i].id;
}
