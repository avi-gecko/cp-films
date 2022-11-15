#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>
#include <fstream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "ru_RU.utf8");
    std::wstring menu_items[4] = {L"1. Открыть файл"
                                , L"2. Экспортировать в файл"
                                , L"3. О программе"
                                , L"4. Выход"};
    const int FILE_SIZE = 1;
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
