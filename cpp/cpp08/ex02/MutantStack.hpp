#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        
        //ITERATOR
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif