#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array<T> &Copy);
        Array<T> &operator=(const Array<T> &copy);
        unsigned int size(void) const;
        unsigned int getLength(void) const;
        T getArrayVal(unsigned int el) const;
        void printElement(unsigned int el) const;
        void printArray() const;

        class WrongArrayElement : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        T *_array;
        unsigned int _length;


};

#include "Array.tpp"
#endif