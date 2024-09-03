#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename container>
void  easyfind(const container &ctn, int occurence);

class ElementNotFind : public std::exception{
    public:
        virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif