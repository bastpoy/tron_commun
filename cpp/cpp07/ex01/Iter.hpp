#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <iomanip>

template <typename arrType>
void f(arrType value)
{
    std::cout << "l'indice est " << value << std::endl;
}

template <typename arrType>
void iter(arrType *array, std::size_t length, void (*f)(arrType&))
{
    for(std::size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}

#endif