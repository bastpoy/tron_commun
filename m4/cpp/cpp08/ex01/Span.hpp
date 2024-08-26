#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>

class Span
{
    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        void addNumber(int number);
        // unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void printSpan() const;

    private:
        std::vector<int> _array;
        unsigned int _N;
        unsigned int _index;

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