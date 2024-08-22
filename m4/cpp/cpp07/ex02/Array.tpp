#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _length(0)
{
    this->_array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n): _length(n)
{
    this->_array = new T[n]();
}

template<typename T>
Array<T>::~Array()
{
    delete []this->_array;
}

template<typename T>
Array<T>::Array(const Array<T> &copy)
{
    *this = copy;
}
template<typename T>
Array<T>  &Array<T>::operator=(const Array<T> &copy)
{
    if(this != &copy)
    {
        this->_length = copy.getLength();
        if(this->_array)
            delete []this->_array;
        this->_array = new T[copy.getLength()]();
        for(unsigned int i = 0; i < this->_length; i++)
        {
            this->_array[i] = copy.getArrayVal(i);
        }
    }
    return (*this);
}

//MEMBER FUNCTIONS

template<typename T>
unsigned int Array<T>::getLength(void) const
{
    return (this->_length);
}

template<typename T>
T Array<T>::getArrayVal(unsigned int el) const
{
    if(el < this->_length)
        return(this->_array[el]);
    else
        throw WrongArrayElement();
}

template<typename T>
void Array<T>::printElement(unsigned int el) const
{
    if(el >= this->_length)
        throw WrongArrayElement();
    else
        std::cout << "Element at index "<< el << " is " << _array[el] << std::endl;
}

template<typename T>
void Array<T>::printArray() const
{
    for(unsigned int i = 0; i < this->getLength(); i++)
    {
        std::cout << this->getArrayVal(i) << " ";
    }
    std::cout << std::endl;
}
//EXCEPTIONS

template<typename T>
const char* Array<T>::WrongArrayElement::what() const throw()
{
    return("Out of range array element");
}

#endif