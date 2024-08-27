#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>

template <typename T>
class MutantStack
{
    public:
        MutantStack<T>();
        ~MutantStack<T>();
        MutantStack<T>(const MutantStack &copy);
        MutantStack<T> &operator=(const MutantStack &copy);

    private:
        std::stack<T> _stack;
};

#endif