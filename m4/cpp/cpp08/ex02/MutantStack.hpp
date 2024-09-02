#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <stack>

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

        //MEMBER FUNCTIONS
        std::stack<T> &get_stack(void) const;

        // STACKS FUNCTIONS
        const T &top(void) const;
        bool empty(void) const;
        void push(const T &value);
        void push_range();
        void pop(void);
        size_t size(void) const;
};

#include "MutantStack.tpp"

#endif