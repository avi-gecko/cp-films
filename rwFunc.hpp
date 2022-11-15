#ifndef RWFUNC_HPP
#define RWFUNC_HPP
#include <iostream>

typedef struct Tfilms
{
    int id;
    std::string title;
    std::string studio;
    std::string  genre;
    int year_publishing;
    bool inStock;
    int year_purchasing;
} Films;

#endif // RWFUNC_HPP
