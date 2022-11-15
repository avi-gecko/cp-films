#include "rwFunc.hpp"
#include <iostream>
#include <fstream>

Films *make_struct(const std::string file, int size)
{
    std::fstream file_d;
    file_d.open(file, std::ios_base::in);
    if (!file_d.is_open())
        return nullptr;
    Films *structures = new Films[size];
    std::string temp;
    for (int i = 0; i < size; ++i)
    {
        std::getline(file_d, temp);
        structures[i].id = std::stoi(temp.substr(0, temp.find(";")));
        temp.erase(0, temp.find(";") + 1);
        structures[i].title = temp.substr(0, temp.find(";"));
        temp.erase(0, temp.find(";") + 1);
        structures[i].studio = temp.substr(0, temp.find(";"));
        temp.erase(0, temp.find(";") + 1);
        structures[i].genre = temp.substr(0, temp.find(";"));
        temp.erase(0, temp.find(";") + 1);
        structures[i].year_publishing = std::stoi(temp.substr(0, temp.find(";")));
        temp.erase(0, temp.find(";") + 1);
        structures[i].inStock = std::stoi(temp.substr(0, temp.find(";")));
        temp.erase(0, temp.find(";") + 1);
        structures[i].year_purchasing = std::stoi(temp.substr(0, temp.find(";")));
    }
    file_d.close();
    return structures;
}
