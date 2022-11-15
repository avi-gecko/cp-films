#include <iostream>
#include "menu.hpp"

void show_menu(int len, const std::string items[])
{
   for(int i = 0; i < len; ++i)
   {
       std::cout << items[i] << '\n';
   }
}
