#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    *this = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
    if(this != &copy)
    {
        std::stack<T>::operator=(copy);
    }
    return (*this);
}

//MEMBER FONCTIONS

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
std::stack<T> &MutantStack<T>::get_stack(void) const
{
    return(this->c);
}

// STACKS FUNCTIONS
template <typename T>
const T & MutantStack<T>::top(void) const
{
    return (std::stack<T>::top());
}

template <typename T>
bool MutantStack<T>::empty(void) const
{
    return (this->c.empty());
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
    std::stack<T>::push(value);
}

template <typename T>
void MutantStack<T>::pop(void)
{
    std::stack<T>::pop();
}

template <typename T>
size_t MutantStack<T>::size(void) const
{
    return (this->c.size());
}
