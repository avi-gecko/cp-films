#ifndef RWFUNC_HPP
#define RWFUNC_HPP
#include <iostream>

typedef struct Tfilms
{
    int id;
    std::wstring title;
    std::wstring studio;
    std::wstring  genre;
    int year_publishing;
    bool in_stock;
    int year_purchasing;
} Films;

Films *make_struct(const std::string file, int size);


#endif // RWFUNC_HPP
