#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits>

class Span
{
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        void addNumber(int number);
        void addMultipleNumbers(std::vector<int>::const_iterator bgn, std::vector<int>::const_iterator end);
        int shortestSpan() const;
        int longestSpan() const;
        void printSpan() const;

    private:
        std::vector<int> _array;
        unsigned int _N;

    class WrongArrayElement : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class notEnoughtElement : public std::exception{
        public:
            virtual const char* what() const throw();
    };
};
#endif