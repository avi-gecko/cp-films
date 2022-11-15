#include "menu.hpp"
#include "rwFunc.hpp"
#include <iostream>
#include <fstream>

int main()
{    
    std::string menu_items[4] = {"1. Открыть файл"
                               , "2. Экспортировать в файл"
                               , "3. О программе"
                               , "4. Выход"};
    const int FILE_SIZE = 1;
    const int MENU_SIZE = 4;
    Films *films = nullptr;
    while (true)
    {
        clear();
        int item;
        show_menu(menu_items, MENU_SIZE);
        std::cin >> item;
        switch(item)
        {
            case 1:
            {
                 if (!films)
                     films = make_struct("films.db", FILE_SIZE);
                 show_file(films, FILE_SIZE);
                 delete[] films;
                 films = nullptr;
                 break;
            }

            case 2:
            {

            }
        }
    }

    return 0;
}
