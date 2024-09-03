#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename container>
void easyfind(container &ctn, int occurence)
{
    typename container::iterator it = std::find(ctn.begin(), ctn.end(), occurence);
    if(it == ctn.end())
        throw ElementNotFind();
    std::cout << "The occurence is at index " << it. << std::endl;
}

const char *ElementNotFind::what() const throw()
{
    return("Element not found inside container");
}

#endif