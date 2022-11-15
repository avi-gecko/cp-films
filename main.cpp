#include "menu.hpp"
#include <iostream>

int main()
{    
    std::string menu_items[4] = {"1. Открыть файл"
                               , "2. Экспортировать файл"
                               , "3. О программе"
                               , "4. Выход"};
    show_menu(4, menu_items);
    return 0;
}
