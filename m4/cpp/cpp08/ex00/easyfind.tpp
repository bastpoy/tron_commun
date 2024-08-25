#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename container>
void easyfind(const container &ctn, int occurence)
{
    typename container::const_iterator it;
    for(it = ctn.begin(); it != ctn.end(); it++)
    {
        if(*it == occurence)
        {
            std::cout << "the occurence is: " << *it << " index "<< std::distance(ctn.begin(), it) << std::endl;
            return;
        }
    }
    throw ElementNotFind();
}

const char *ElementNotFind::what() const throw()
{
    return("Element not found inside container");
}

#endif