#include "Span.hpp"

Span::Span(): _N(0)
{
    this->_array = std::vector<int>(0);
}
Span::~Span()
{}
Span::Span(unsigned int N): _N(N)
{
    this->_array = std::vector<int>(0,N);
}
Span::Span(const Span &copy): _N(copy._N)
{
    *this = copy;
}
Span &Span::operator=(const Span &copy)
{
    if(this != &copy)
    {
        this->_N = copy._N;
        _array = copy._array;
    }
    return (*this);
}

// MEMBER FUNCTIONS

void Span::addNumber(int number)
{
    if(this->_array.size() > this->_N)
        throw WrongArrayElement();
    this->_array.push_back(number);
}

int Span::longestSpan() const
{
    if(this->_N <= 1)
        throw notEnoughtElement();
    int max = *std::max_element(this->_array.begin(), this->_array.end());
    int min = *std::min_element(this->_array.begin(), this->_array.end());
    return (max - min);
}

int Span::shortestSpan() const
{
    std::vector<int> copy = this->_array;
    unsigned int minspan = std::numeric_limits<unsigned int>::max();
    std::sort(copy.begin(), copy.end());

    if(this->_N <= 1)
        throw notEnoughtElement();
    for(std::vector<int>::const_iterator it = copy.begin(); it != copy.end() - 1 ; it++)
    {
        unsigned int span = *(it + 1) - *it;
        if(span < minspan)
            minspan = span;
    }
    return (minspan);
}

void Span::printSpan() const
{
    std::vector<int>::const_iterator it;
    for(it = this->_array.begin(); it != this->_array.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void Span::addMultipleNumbers(std::vector<int>::const_iterator bgn, std::vector<int>::const_iterator end)
{
    this->_array.insert(this->_array.end(), bgn, end);
    if(_array.size() > _N)
        throw notEnoughtElement();
}

//Exceptions

const char* Span::WrongArrayElement::what() const throw()
{
    return("Out of range array element");
}

const char* Span::notEnoughtElement::what() const throw()
{
    return("Not enought element inside the array");
}