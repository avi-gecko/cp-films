#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "rwFunc.hpp"

void show_menu(const std::wstring items[], int len);
void show_file(const Films structures[], int len);
void wait();
void clear();
void about();

#endif // MENU_HPP
