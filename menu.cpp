#include <iostream>
#include "menu.hpp"

void menu(int len, std::string items)
{
   for(int i = 0; i < len; ++i)
   {
       std::cout << items[i] << '\n';
   }
}
