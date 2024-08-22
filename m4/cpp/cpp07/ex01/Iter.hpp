#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename arrType>
void *el(arrType value)
{
    std::cout << "l'indice est " << value << std::endl;
}

template <typename arrType> 
void iter(arrType *array, std::size_t length, arrType function)
{
    for(std::size_t i = 0; i < length; i++)
    {
        function(array[i]);
    }
}

#endif