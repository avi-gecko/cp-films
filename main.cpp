#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <clocale>

int main()
{
    #ifdef _WIN32
    setlocale(LC_ALL, "cp1251");
    #elif __linux__
    setlocale(LC_ALL, "ru_RU.utf8");
    #endif
    std::wstring menu_items[4] = {L"1. Открыть файл"
                                , L"2. Экспортировать в файл"
                                , L"3. О программе"
                                , L"4. Выход"};
    const int FILE_SIZE = 2;
    const int MENU_SIZE = 4;
    const std::string FILE_NAME= "films.db";

    Films *films = nullptr;
    while (true)
    {
        clear();
        int item;
        show_menu(menu_items, MENU_SIZE);
        std::wcin >> item;
        switch(item)
        {
            case 1:
            {
                 if (!films)
                     films = make_struct(FILE_NAME, FILE_SIZE);
                 show_file(films, FILE_SIZE);
                 delete[] films;
                 films = nullptr;
                 break;
            }

            case 2:
            {
                if (!films)
                    films = make_struct(FILE_NAME, FILE_SIZE);
                export_struct(films, FILE_SIZE);
                delete[] films;
                break;
            }

            case 3:
            {
                about();
                break;
            }

            case 4:
            {
                exit(0);
            }
            default:
            {
                std::wcout << L"Неверный ввод" << std::endl;
                wait();
            }
        }
    }

    return 0;
}
